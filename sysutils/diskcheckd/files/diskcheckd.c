/*-
 * Copyright (c) 2000, 2001 Ben Smithurst <ben@FreeBSD.org>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * geom-aware portions of logreaderror() Copyright (c) 2015 Perry Hutchison
 * <perryh@pluto.rain.com>, licensed on the same terms as above.
 */

#include <sys/param.h>
#include <sys/sysctl.h>

#include <ctype.h>
#include <err.h>
#include <errno.h>
#include <fcntl.h>
#include <limits.h>
#include <paths.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <syslog.h>
#include <time.h>
#include <unistd.h>

#define DKTYPENAMES
#define FSTYPENAMES
#include <sys/disk.h>
#include <sys/disklabel.h>
#include <sys/diskmbr.h>

#ifndef _PATH_CONF
#define	_PATH_CONF	"/usr/local/etc/diskcheckd.conf"
#endif

#define	_PATH_SAVE	_PATH_VARDB"diskcheckd.offsets"

#define	READ_SIZE (64 << 10)

/*
 * Customize format strings according to what printf et al. want for a quad_t.
 *
 * This should not be necessary -- the whole point of %qd is to match a quad_t
 * -- but in LP64 a quad_t is the same size as a long and yet %qd is treated as
 * equivalent to %lld (which is correct only if a long is 32 bits, as in ILP32).
 */
#ifdef	LP64
#define QD "%ld"
#else
#define	QD "%qd"
#endif

struct disk {
	int fd;
	char *device;
	off_t size;
	int secsize;
	int days, rate, errors;
	long long interval, next;
};

volatile sig_atomic_t got_sighup = 0, got_sigterm = 0;
volatile int debug = 0;

char **getdisknames(char **, int);
off_t dseek(struct disk *, off_t, int);
struct disk *readconf(const char *);
void getdisksize(struct disk *);
void logreaderror(struct disk *, int);
void readchunk(struct disk *, char *);
void readoffsets(struct disk *, const char *);
void sighup(int);
void sigterm(int);
void updateproctitle(struct disk *);
void usage(void);
void writeoffsets(struct disk *, const char *);

int
main(int argc, char *argv[]) {
	char *buf;
	struct disk *disks, *dp;
	int ch, ok;
	long long minwait, nextwait;
	struct sigaction sa;
	long long counter;
	int initial_debug;
	const char *conf_file, *save_file;

	conf_file = _PATH_CONF;
	save_file = _PATH_SAVE;
	debug = 0;

	while ((ch = getopt(argc, argv, "df:o:")) != -1)
		switch (ch) {
		case 'd':
			if (debug)
				debug *= 2;
			else
				debug = 1;
			break;
		case 'f':
			conf_file = optarg;
			break;
		case 'o':
			save_file = optarg;
			break;
		default:
			usage();
			/* NOTREACHED */
		}

	argv += optind;
	argc -= optind;

	if (argc != 0)
		usage();

	initial_debug = debug;

	openlog("diskcheckd", LOG_CONS|LOG_PID|(debug?LOG_PERROR:0),
		LOG_DAEMON);

	if (!debug && daemon(0, 0) < 0) {
		syslog(LOG_NOTICE, "daemon() failure: %m");
		exit(EXIT_FAILURE);
	}

	sa.sa_handler = sigterm;
	sa.sa_flags = SA_RESTART;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGTERM, &sa, NULL);
	sigaction(SIGINT, &sa, NULL);

	sa.sa_handler = sighup;
	sigaction(SIGHUP, &sa, NULL);

	/* Read the configuration file and the saved offsets */
	disks = readconf(conf_file);
	readoffsets(disks, save_file);

	if ((buf = malloc(READ_SIZE)) == NULL) {
		syslog(LOG_NOTICE, "malloc failure: %m");
		exit(EXIT_FAILURE);
	}

	/* The main disk checking loop.
	 *
	 * We wait the shortest amount of time we need to before
	 * another disk is due for a read -- this time is updated
	 * in the 'nextwait' variable, which is then copied to
	 * 'minwait'.  After a sleep, 'minwait' is subtracted from
	 * each disk's 'next' field, and when that reaches zero,
	 * that disk is read again.
	 */
	counter = 0LL;
	minwait = 0LL;
	while (!got_sigterm) {
		ok = 0;
		nextwait = LLONG_MAX;
		for (dp = disks; dp->device != NULL; dp++)
			if (dp->fd != -1) {
				if (debug > 1)
					fprintf(stderr,
						"%s:  next(%qd) -= %qd\n",
						dp->device, dp->next, minwait);
				if ((dp->next -= minwait) == 0) {
					ok = 1;
					readchunk(dp, buf);
				}

				/* XXX debugging */
				if (dp->next < 0LL) {
					syslog(LOG_NOTICE,
					  "dp->next < 0 for %s", dp->device);
					abort();
				}

				if (dp->next < nextwait)
					nextwait = dp->next;
			}

		if (!ok) {
			syslog(LOG_EMERG, "all disks had read errors");
			exit(EXIT_FAILURE);
		}

		/* 300 seconds => 5 minutes */
		if (counter >= 300000000LL) {
			if (debug)
				fprintf(stderr, "counter rollover %qd => 0\n",
					counter);
			updateproctitle(disks);
			writeoffsets(disks, save_file);
			counter = 0LL;
		}

		minwait = nextwait;
		if (debug > 1) {
			--debug;
			fprintf(stderr, "sleep %qd, counter %qd\n",
				minwait, counter);
		}

		/*
		 * Handle whole seconds and usec separately to avoid overflow
		 * when calling usleep -- useconds_t is only 32 bits on at
		 * least some architectures, and minwait (being long long)
		 * may exceed INT_MAX.
		 */
		if (minwait > 1000000LL)
			sleep((unsigned int)(minwait / 1000000));
		if ((minwait % 1000000) > 0)
			usleep((useconds_t)(minwait % 1000000));
		counter += minwait;

		if (got_sighup) {
			/*
			 * Got a SIGHUP, so save the offsets, free the
			 * memory used for the disk structures, and then
			 * re-read the config file and the disk offsets.
			 */
			if (debug) {
				fprintf(stderr, "got SIGHUP, counter == %qd\n",
					counter);
				debug = initial_debug;
			}
			writeoffsets(disks, save_file);
			for (dp = disks; dp->device != NULL; dp++) {
				free(dp->device);
				close(dp->fd);
			}
			free(disks);
			disks = readconf(conf_file);
			readoffsets(disks, save_file);
			minwait = 0LL;
			got_sighup = 0;
		}
	}

	if (debug)
		fprintf(stderr, "got %s, counter == %qd\n",
			got_sigterm==SIGTERM?"SIGTERM":"SIGINT", counter);
	writeoffsets(disks, save_file);
	return (EXIT_SUCCESS);
}

/*
 * Read the next chunk from the specified disk, retrying if necessary.
 */
void
readchunk(struct disk *dp, char *buf) {
	ssize_t n;
	int s;

	dp->next = dp->interval;
	n = read(dp->fd, buf, READ_SIZE);
	if (n == 0) {
		eof:
		syslog(LOG_INFO, "reached end of %s with %d errors",
		    dp->device, dp->errors);
		dseek(dp, 0, SEEK_SET);
		dp->errors = 0;
		return;
	} else if (n > 0)
		return;

	/*
	 * Read error, retry in smaller chunks.
	 */
	logreaderror(dp, READ_SIZE);

	for (s = 0; s < READ_SIZE; s += 512) {
		n = read(dp->fd, buf, 512);
		if (n == 0)
			goto eof;
		else if (n < 0) {
			/* log the error and seek past it. */
			logreaderror(dp, 512);
			dseek(dp, 512, SEEK_CUR);
		}
	}
}

const char *
fstypename(u_int8_t type) {
	static char buf[32];

	if (type < FSMAXTYPES)
		return (fstypenames[type]);
	else {
		snprintf(buf, sizeof buf, "%u", type);
		return (buf);
	}
}

/*
 * Report a read error, logging how many bytes were trying to be read, which
 * sector they were being read from, and try to also find out what that sector
 * is used for.
 */
void
logreaderror(struct disk *dp, int nbytes) {
	quad_t secno;
	off_t saved_offset;
	char newdev[512];

#ifdef	DIOCGDINFO
	int fd, slice, part;
	struct dos_partition *dos;
	struct disklabel label;
	char buf[512];
#else	/* DIOCGDINFO */
	static size_t geomSize = 0;
	static char * geomConf = NULL;
	char * cp;
	static size_t partLen = 31;
	static char *part = NULL;
	quad_t relsec = -1;
	char *typefld = NULL;
#endif	/* DIOCGDINFO */

	saved_offset = dseek(dp, 0, SEEK_CUR);
	secno = (quad_t)saved_offset / dp->secsize;
	dp->errors++;

	syslog(LOG_NOTICE, "error reading %d bytes from sector " QD " on %s",
	    nbytes, secno, dp->device);

#ifdef	DIOCGDINFO
	/*
	 * First, find out which slice it's in.  To do this, we seek to the
	 * start of the disk, read the first sector, and go through the DOS
	 * slice table.
	 */
	if (dseek(dp, 0, SEEK_SET) == -1) {
		syslog(LOG_NOTICE, "could not seek to start of disk: %m");
		exit(EXIT_FAILURE);
	}

	if (read(dp->fd, buf, sizeof buf) != sizeof buf) {
		dseek(dp, saved_offset, SEEK_SET);
		return;
	}

	/* seek back to where we were */
	if (dseek(dp, saved_offset, SEEK_SET) == -1) {
		syslog(LOG_NOTICE,
		       "could not seek to previous position"
		       "after reading first sector: %m");
		exit(EXIT_FAILURE);
	}

	// TODO:  should validate DOS partition table (vs GPT or dedicated)
	dos = (struct dos_partition *)&buf[DOSPARTOFF];
	for (slice = 0; slice < NDOSPART; slice++)
		if (dos[slice].dp_start <= secno &&
		  secno < dos[slice].dp_start + dos[slice].dp_size)
			break;

	if (slice == NDOSPART) {
		syslog(LOG_NOTICE,
		  "sector " QD " on %s doesn't appear "
		  "to be within any DOS slice", secno, dp->device);
		return;
	}

	/* Make secno relative to this slice */
	secno -= dos[slice].dp_start;

	snprintf(newdev, sizeof newdev, "%ss%d", dp->device, slice + 1);
	syslog(LOG_DEBUG, "bad sector seems to be within %s", newdev);

	/* Check the type of that partition. */
	if (dos[slice].dp_typ != DOSPTYP_386BSD) {
		/* If not a BSD slice, we can't do much more. */
		syslog(LOG_NOTICE, "last bad sector is sector " QD
		    " on device %s, type %02x", secno, newdev,
		    dos[slice].dp_typ);
		return;
	}

	if ((fd = open(newdev, O_RDONLY)) < 0) {
		syslog(LOG_NOTICE, "open %s failure: %m", newdev);
		return;
	}

	/* Try to read the disklabel from that device. */
	if (ioctl(fd, DIOCGDINFO, &label) < 0) {
		syslog(LOG_NOTICE, "DIOCGDINFO on %s failed: %m",
		    newdev);
		return;
	}

	/* Check which partition this sector is in. */
	for (part = 0; part < MAXPARTITIONS; part++)
		if (part != 2 && /* skip 'c' partition */
		    label.d_partitions[part].p_offset <= secno &&
		    secno < label.d_partitions[part].p_offset +
		            label.d_partitions[part].p_size)
			break;

	if (part == MAXPARTITIONS) {
		syslog(LOG_NOTICE,
		  "sector " QD " on %s doesn't appear "
		  "to be within any BSD partition", secno, newdev);
		return;
	}

	secno -= label.d_partitions[part].p_offset;
	snprintf(newdev, sizeof newdev, "%ss%d%c",
	    dp->device, slice + 1, 'a' + part);
	syslog(LOG_DEBUG, "bad sector seems to be within %s", newdev);
	if (label.d_partitions[part].p_fstype != FS_BSDFFS) {
		/* Again, if not a BSD partition, can't do much. */
		syslog(LOG_NOTICE, "last bad sector is sector " QD
		    " on device %s, type %s", secno, newdev,
		    fstypename(label.d_partitions[part].p_fstype));
		return;
	}
#else	/* DIOCGDINFO */
	if (geomSize == 0) {
		sysctlbyname("kern.geom.conftxt", NULL, &geomSize, NULL, 0);
		if (geomSize <= 0) {
			printf("sysctlbyname() returned size = %d\n", geomSize);
			geomSize = 0;
			exit(EXIT_FAILURE);
		}
		geomConf = malloc(geomSize);
		if (geomConf == NULL) {
			printf("malloc(%d) returned NULL\n", geomSize);
			geomSize = 0;
			exit(EXIT_FAILURE);
		}
		if (sysctlbyname("kern.geom.conftxt", geomConf, &geomSize,
				 NULL, 0) != 0) {
			perror("sysctlbyname()");
			geomSize = 0;
			free(geomConf);
			geomConf = NULL;
			exit(EXIT_FAILURE);
		}
	}
	if (part == NULL)
		part = malloc(partLen + 1);

	for ( cp = geomConf ; *cp ; ++cp ) {
		// find line "0 DISK " matching current disk, using
		// strncmp because where cp points is not null-terminated
		// (All DISK lines, and only DISK lines, are at level 0.)
		// Magic numbers:  7 == strlen("0 DISK "); 5 == strlen("/dev/")
		if (strncmp(cp, "0 DISK ", 7) == 0
		 && strncmp(&cp[7], &dp->device[5], strlen(dp->device) - 5) == 0
		 && cp[7 + strlen(dp->device) - 5] == ' ') {
			for (;;) {
				// scan to end of line
				while (cp[1] && *cp != '\n')
					++cp;
				++cp;	// start of next line
				// Find PART line containing the failed sector;
				// must be on same disk => stop upon finding
				// another DISK line.  If more than one matching
				// PART -- due to nested geoms -- use the last
				// (innermost).
				if (*cp == '\0' || *cp == '0')
					break;	// end of current DISK's entries
				// scan to end of level number
				while (cp[1] && *cp != ' ')
					++cp;
				if (strncmp(cp, " PART ", 6) == 0) {
					char *pp = &cp[6];
					int pl = strchr(pp, ' ') - pp;
					quad_t mediasize, offset;
					long secsize;

					cp = pp + pl;	// cp -> mediasize
					mediasize = strtoq(cp, &cp, 10);
					secsize = strtol(cp, &cp, 10);
					mediasize /= secsize;
					cp = strchr(cp, 'o') + 1;
					offset = strtoq(cp, &cp, 10) / secsize;
					if (secno >= offset
					 && (secno - offset) < mediasize) {
						if (pl > partLen) {
							part = realloc(part,
									pl+1);
							partLen = pl;
						}
						strncpy(part, pp, pl);
						part[pl] = '\0';
						relsec = secno - offset;
						typefld = cp + 1;
					}
				}
			}
		}
		// scan to end of line
		while (cp[1] && *cp != '\n')
			++cp;
	}
////	printf("part %s, relsec %qd, typefld %p: %.27s\n",
////		part, relsec, typefld, typefld);
	secno = relsec;
	strncpy(newdev, part, sizeof(newdev) - 1);
	newdev[sizeof(newdev) - 1] = '\0';		// paranoia
#endif	/* DIOCGDINFO */

	syslog(LOG_NOTICE, "last bad sector is sector " QD
	  " on 4.2BSD filesystem %s", secno, newdev);

	/*
	 * XXX: todo: find out which file on the BSD filesystem uses this
	 * sector...
	 */
}

/*
 * Read the offsets written by writeoffsets().
 */
void
readoffsets(struct disk *disks, const char *save_file) {
	FILE *fp;
	struct disk *dp;
	char *space, buf[1024];

	if ((fp = fopen(save_file, "r")) == NULL) {
		if (debug > 1 && errno == ENOENT)
			fprintf(stderr, "open %s failed: %s [continuing]\n",
				save_file, strerror(errno));
		if (errno != ENOENT)
			syslog(LOG_NOTICE, "open %s failed: %m", save_file);
		return;
	}

	while (fgets(buf, sizeof buf, fp) != NULL) {
		if ((space = strchr(buf, ' ')) == NULL)
			continue;
		*space = '\0';

		for (dp = disks;
		    dp->device != NULL && strcmp(dp->device, buf) != 0; dp++)
			; /* nothing */

		if (dp->device != NULL) {
			if (debug)
				fprintf(stderr, "%s: seek %s", buf, space + 1);
			dseek(dp, (off_t)strtoq(space + 1, NULL, 0), SEEK_SET);
		}
	}
	fclose(fp);
	if (debug)
		fprintf(stderr, "readoffsets: done\n");
}

/*
 * Save the offsets we've reached for each disk to a file, so we can start
 * at that position next time the daemon is started.
 */
void
writeoffsets(struct disk *disks, const char *save_file) {
	FILE *fp;
	struct disk *dp;

	if ((fp = fopen(save_file, "w")) == NULL) {
		syslog(LOG_NOTICE, "open %s failed: %m", save_file);
		return;
	}

	if (debug)
		fprintf(stderr,
			"#\tposition/size\tdays\trate\terrors\tintvl\tnext\n");
	for (dp = disks; dp->device != NULL; dp++)
		if (strcmp(dp->device, "*") != 0) {
			fprintf(fp, "%s " QD "\n", dp->device,
			    (quad_t)dseek(dp, 0, SEEK_CUR));
			if (debug) {
				fprintf(stderr, "%s " QD "\n", dp->device,
					(quad_t)dseek(dp, 0, SEEK_CUR));
				fprintf(stderr,
					"#\t" QD "\t%d\t%d\t%d\t" QD "\t" QD
					"\n",
					(quad_t)dp->size, dp->days, dp->rate,
					dp->errors, dp->interval, dp->next);
			}
		}
	fclose(fp);
}

/*
 * Set the process title so it's easy to see using ps(1) how much has been
 * done.
 */
void
updateproctitle(struct disk *disks) {
	struct disk *dp;
	char *bp, *p;
	static char *buf;
	static size_t bufsize;
	size_t size;
	int inc, ret;
	double percent;

	bp = buf;
	size = bufsize;
	for (dp = disks; dp->device != NULL; dp++) {
		p = dp->device;
		if (strcmp(p, "*") == 0)
			continue;
		if (strncmp(p, _PATH_DEV, sizeof _PATH_DEV - 1) == 0)
			p += sizeof _PATH_DEV - 1;

		percent = 100 * (double)dseek(dp, 0, SEEK_CUR) / dp->size;
		if ((ret = snprintf(bp, size, "%s %.2f%%, ", p, percent)) < 0)
			ret = 0;
		if ((size_t)ret >= size) {
			inc = ((ret + 1023) >> 10) << 10;
			size += inc;
			bufsize += inc;
			if ((buf = reallocf(buf, bufsize)) == NULL) {
				/* Not fatal. */
				syslog(LOG_NOTICE, "reallocf failure: %m");
				bufsize = 0;
				return;
			}
			bp = buf + bufsize - size;
			ret = snprintf(bp, size, "%s %.2f%%, ", p, percent);
			if (ret < 0)
				ret = 0;
		}
		bp += ret;
		size -= ret;
	}

	if (buf != NULL) {
		/* Remove the trailing comma. */
		if (&bp[-2] >= buf)
			bp[-2] = '\0';
		setproctitle("%s", buf);
	}
}

/* used to keep track of which fields have been specified */
#define FL_SIZE_SPEC 1
#define FL_DAYS_SPEC 2
#define FL_RATE_SPEC 4

/*
 * Read the configuration file, set the rate appropriately for each disk,
 * and get a file descriptor for each disk.
 */
struct disk *
readconf(const char *conf_file) {
	FILE *fp;
	char buf[1024], *line, *field, *ep, **np, **np0;
	int fields, flags;
	struct disk *disks, *dp, *odisks;
	int numdisks, onumdisks;
	double dval;
	long lval;
	int linenum;
	char **skip;
	int numskip;

	if ((fp = fopen(conf_file, "r")) == NULL) {
		syslog(LOG_NOTICE, "open %s failure: %m", conf_file);
		exit(EXIT_FAILURE);
	}

	numdisks = 0;
	disks = NULL;
	linenum = 0;
	skip = NULL;
	numskip = 0;

	/* Step 1: read and parse the configuration file. */
	while (fgets(buf, sizeof buf, fp) != NULL) {
		line = buf;
		linenum++;
		while (isspace(*line))
			line++;
		if (*line == '#' || *line == '\n' || *line == '\0')
			continue;

		/* First, if the line starts with '!', this is a disk name
		 * to ignore.  For example, '!md' will skip all '/dev/md*'
		 * devices.
		 */
		if (*line == '!') {
			line++;
			while (isspace(*line))
				line++;
			field = strsep(&line, " \t\n");
			if (field == NULL || *field == '\0') {
				syslog(LOG_NOTICE, "%s:%d: missing disk name",
				  conf_file, linenum);
				continue;
			}

			numskip++;
			if ((skip = reallocf(skip,
			  numskip * sizeof (*skip))) == NULL) {
				syslog(LOG_NOTICE, "reallocf failure: %m");
				exit(EXIT_FAILURE);
			}

			if ((skip[numskip-1] = strdup(field)) == NULL) {
				syslog(LOG_NOTICE, "strdup failure: %m");
				exit(EXIT_FAILURE);
			}

			continue;
		}

		fields = flags = 0;
		while ((field = strsep(&line, " \t\n")) != NULL) {
			if (*field == '\0')
				continue;

			/*
			 * If this is the first field on a line, allocate
			 * space for one more disk structure.
			 */
			if (fields == 0 && (disks = reallocf(disks,
			    (numdisks + 1) * sizeof (*disks))) == NULL) {
				syslog(LOG_NOTICE, "reallocf failure: %m");
				exit(EXIT_FAILURE);
			}

			dp = &disks[numdisks];
			switch (fields++) {
			case 0:
				/* device name */
				if ((dp->device = strdup(field)) == NULL) {
					syslog(LOG_NOTICE,
					    "strdup failure: %m");
					exit(EXIT_FAILURE);
				}
				dp->fd = -1;
				dp->rate = -1;
				dp->size = -1;
				dp->interval = -1LL;
				dp->next = 0LL;
				break;
			case 1:
				/* size */
				if (strcmp(field, "*") == 0)
					break;
				flags |= FL_SIZE_SPEC;
				dval = strtod(field, &ep);
				if (dval < 0) {
					syslog(LOG_NOTICE,
					    "%s:%d: size cannot be negative",
					    conf_file, linenum);
					exit(EXIT_FAILURE);
				}
				if (strcasecmp(ep, "M") == 0)
					dp->size = dval * 1024 * 1024;
				else if (strcasecmp(ep, "G") == 0)
					dp->size = dval * 1024 * 1024 * 1024;
				else if (*ep == '\0')
					dp->size = dval;
				else {
					syslog(LOG_NOTICE,
					    "%s:%d: bad suffix \"%s\" on "
					    "size \"%s\"", conf_file,
					    linenum, ep, field);
					exit(EXIT_FAILURE);
				}
				break;
			case 2:
				/* days */
				if (strcmp(field, "*") == 0)
					break;
				flags |= FL_DAYS_SPEC;
				lval = strtol(field, &ep, 0);
				if (ep == field || *ep != '\0' ||
				    lval <= 0) {
					syslog(LOG_NOTICE,
					    "%s:%d: bad number of days",
					    conf_file, linenum);
					exit(EXIT_FAILURE);
				}
				dp->days = lval;
				break;
			case 3:
				/* rate */
				if (strcmp(field, "*") == 0)
					break;
				flags |= FL_RATE_SPEC;
				lval = strtol(field, &ep, 0);
				if (ep == field || *ep != '\0' ||
				    lval <= 0) {
					syslog(LOG_NOTICE, "%s:%d: bad rate",
					    conf_file, linenum);
					exit(EXIT_FAILURE);
				}
				dp->rate = lval * 1024;
				break;
			default:
				/* Report error at end of line. */
				break;
			}
		}
		if (fields != 4) {
			syslog(LOG_NOTICE,
			    "%s:%d: %d fields, should be 4",
			    conf_file, linenum, fields);
			exit(EXIT_FAILURE);
		}
		if (flags != (FL_SIZE_SPEC|FL_DAYS_SPEC) &&
		    flags != FL_DAYS_SPEC &&
		    flags != FL_RATE_SPEC) {
			syslog(LOG_NOTICE,
			    "%s:%d: should specify frequency "
			    "or rate, not both", conf_file,
			    linenum);
			exit(EXIT_FAILURE);
		}
		numdisks++;
	}
	fclose(fp);

	if (numdisks == 0) {
		syslog(LOG_NOTICE, "no disks specified");
		exit(EXIT_FAILURE);
	}

	/*
	 * Step 2: expand any dp->device == "*" entries.  onumdisks is used
	 * so that we don't keep checking dp->device for the new disks as
	 * they're added, since that's pointless.
	 */
	onumdisks = numdisks;
	for (dp = disks; dp < disks + onumdisks; dp++) {
		if (strcmp(dp->device, "*") == 0) {
			for (np = np0 = getdisknames(skip, numskip); *np != NULL; np++) {
				odisks = disks;
				if ((disks = reallocf(disks,
				    (numdisks + 1) * sizeof (*disks))) == NULL) {
					syslog(LOG_NOTICE,
					  "reallocf failure: %m");
					exit(EXIT_FAILURE);
				}

				/* "disks" pointer may have changed. */
				dp = disks + (dp - odisks);

				disks[numdisks].rate = dp->rate;
				disks[numdisks].size = dp->size;
				disks[numdisks].days = dp->days;
				disks[numdisks].interval = dp->interval;
				disks[numdisks].next = 0LL;
				disks[numdisks].device = *np;
				numdisks++;
			}

			/* Don't free the individual pointers, since they're
			 * used as new dp->device entries.
			 */
			free(np0);
		}
	}

	/* Step 3: open all the disks and set the rate to check at
	 * appropriately.  Use "onumdisks" because numdisks changes within
	 * the loop.
	 */
	onumdisks = numdisks;
	for (dp = disks; dp < disks + onumdisks; dp++) {
		if (strcmp(dp->device, "*") == 0) {
			numdisks--;
			continue;
		}

		if ((dp->fd = open(dp->device, O_RDONLY)) < 0) {
			syslog(LOG_NOTICE, "open %s failed: %m", dp->device);
			numdisks--;
			continue;
		}

		dp->errors = 0;

		/*
		 * Set the rate appropriately.  We always read 64KB blocks,
		 * at a rate of 1 block per n seconds, where we adjust n to
		 * make the overall rate close to what the user specified.
		 */
		if (dp->size < 0)
			getdisksize(dp);
		if (dp->rate < 0)
			dp->rate = (dp->size + dp->days * 43200)
				   / (dp->days * 86400);

		/*   * 1000000 => convert seconds to usec   */
		if (dp->rate == 0)
			/* paranoia, should never really happen */
			dp->interval = (long long)READ_SIZE * 1000000;
		else
			dp->interval = ((long long)READ_SIZE * 1000000)
				       / dp->rate;

		if (debug > 1)
			fprintf(stderr, "%s:  rate %d  intvl %qd  next %qd\n",
				dp->device, dp->rate, dp->interval, dp->next);
	}

	if (numdisks == 0) {
		syslog(LOG_NOTICE, "no disks usable");
		exit(EXIT_FAILURE);
	}

	/* Add a final entry with dp->device == NULL to end the array. */
	if ((disks = reallocf(disks,
	    (onumdisks + 1) * sizeof (*disks))) == NULL) {
		syslog(LOG_NOTICE, "reallocf failure: %m");
		exit(EXIT_FAILURE);
	}
	disks[onumdisks].device = NULL;

	return (disks);
}

/*
 * Read in the specified disk's size from the disklabel.
 */
void
getdisksize(struct disk *dp) {
	struct disklabel label;
#if __FreeBSD_version >= 500040
	off_t mediasize;
	unsigned sectorsize;

	if (ioctl(dp->fd, DIOCGSECTORSIZE, &sectorsize) < 0) {
		syslog(LOG_NOTICE, "DIOCGSECTORSIZE on %s failed: %m",
		    dp->device);
		exit(EXIT_FAILURE);
	}
	if (ioctl(dp->fd, DIOCGMEDIASIZE, &mediasize) < 0) {
		syslog(LOG_NOTICE, "DIOCGMEDIASIZE on %s failed: %m",
		    dp->device);
		exit(EXIT_FAILURE);
	}
	dp->secsize = label.d_secsize = sectorsize;
	dp->size = mediasize;
#else
	if (ioctl(dp->fd, DIOCGDINFO, &label) < 0) {
		syslog(LOG_NOTICE, "DIOCGDINFO on %s failed: %m",
		    dp->device);
		exit(EXIT_FAILURE);
	}

	dp->secsize = label.d_secsize;
	dp->size = (off_t)label.d_secperunit * label.d_secsize;
#endif

	if (label.d_secsize != 512)
		syslog(LOG_NOTICE,
		    "%s has %d byte sectors, may cause minor problems",
		    dp->device, label.d_secsize);
}

off_t
dseek(struct disk *dp, off_t offset, int whence) {
	off_t n;

	if ((n = lseek(dp->fd, offset, whence)) == -1) {
		syslog(LOG_NOTICE, "seek failure on %s: %m", dp->device);
		close(dp->fd);
		dp->fd = -1;
	}
	return (n);
}

/*
 * Attempt to get a list of all disk names using the `kern.disks' sysctl
 * variable.  An NULL terminated list of pointers to these disks' pathnames
 * is returned.
 */
char **
getdisknames(char **skip, int numskip) {
	char *string, *field;
	size_t size, numdisks;
	char **disks;
	int i;

	if (sysctlbyname("kern.disks", NULL, &size, NULL, 0) != 0 &&
	    errno != ENOMEM) {
		syslog(LOG_NOTICE, "sysctl kern.disks failure: %m");
		exit(EXIT_FAILURE);
	}
	if ((string = malloc(size)) == NULL) {
		syslog(LOG_NOTICE, "malloc failure: %m");
		exit(EXIT_FAILURE);
	}
	if (sysctlbyname("kern.disks", string, &size, NULL, 0) != 0) {
		syslog(LOG_NOTICE, "sysctl kern.disks failure: %m");
		exit(EXIT_FAILURE);
	}

	disks = NULL;
	numdisks = 0;
	while ((field = strsep(&string, " ")) != NULL) {
		/* check for disks we ignore */
		for (i = 0; i < numskip; i++)
			if (strncmp(field, skip[i], strlen(skip[i])) == 0)
				break;
		if (i < numskip)
			continue;

		if ((disks = reallocf(disks,
		  (numdisks + 1) * sizeof (*disks))) == NULL) {
			syslog(LOG_NOTICE, "reallocf failure: %m");
			exit(EXIT_FAILURE);
		}
		if (asprintf(&disks[numdisks],
		  "%s%s", _PATH_DEV, field) < 0) {
			syslog(LOG_NOTICE, "asprintf failure: %m");
			exit(EXIT_FAILURE);
		}
		numdisks++;
	}

	if ((disks = reallocf(disks,
	  (numdisks + 1) * sizeof (*disks))) == NULL) {
		syslog(LOG_NOTICE, "strdup failure: %m");
		exit(EXIT_FAILURE);
	}
	disks[numdisks] = NULL;

	free(string);
	return (disks);
}

void
sighup(int sig) {

	sig = sig;
	got_sighup = 1;
}

void
sigterm(int sig) {

	got_sigterm = sig;
}

void
usage(void) {

	fprintf(stderr,
	    "usage: diskcheckd [-d] [-f conf_file] [-o save_file]\n");
	exit(EXIT_FAILURE);
}
