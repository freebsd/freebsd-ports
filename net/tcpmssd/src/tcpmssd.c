/*-
 * Copyright (c) 2000 Ruslan Ermilov
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
 * $FreeBSD$
 */

#include <sys/param.h>
#include <sys/socket.h>
#include <sys/sysctl.h>
#include <net/if.h>
#include <net/if_dl.h>
#include <net/route.h>
#include <netinet/in_systm.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <err.h>
#include <errno.h>
#include <paths.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static void correct_mss(struct tcphdr *, ssize_t len, u_int16_t);
static int if_mtu(const char *, u_long *);
static void sigterm_handler(int);
static void usage(void);

static int both;
static int verbose;

char pidfilename[MAXPATHLEN];

/*-
 * We are in liberal position about MSS
 * (RFC 879, section 7).
 */
#define MAXMSS(mtu)	(mtu - sizeof(struct ip) - sizeof(struct tcphdr))

int
main(int argc, char *argv[])
{
	char pkt[IP_MAXPACKET];
	ssize_t pktlen, hlen;
	struct ip *pip = (struct ip *)pkt;
	struct sockaddr_in sin;
	socklen_t sinlen;
	int s;
	int mflag;
	u_long mtu;
	u_int16_t maxmss;
	int rtsock;
	int ifindex;
	int pflag;
	u_short port;
	int ch;
	fd_set fdset;

	mflag = pflag = 0;
	port = 0;			/* XXX gcc -Wuninitialized */
	ifindex = 0;
	rtsock = -1;

	while ((ch = getopt(argc, argv, "bi:m:p:v")) != -1)
		switch (ch) {
		case 'b':
			both = 1;
			break;
		case 'i':
			if (!(ifindex = if_mtu(optarg, &mtu))) {
				errx(1, "unknown interface %s", optarg);
				/* NOTREACHED */
			}
			snprintf(pidfilename, sizeof pidfilename,
				 "%stcpmssd.%s.pid", _PATH_VARRUN, optarg);
			break;
		case 'm':
			if ((mtu = atoi(optarg)) < 68) {
				errx(1, "invalid MTU value");
				/* NOTREACHED */
			}
			mflag++;
			break;
		case 'p':
			port = htons(atoi(optarg));
			pflag++;
			break;
		case 'v':
			verbose = 1;
			break;
		case '?':
		default:
			usage();
			/* NOTREACHED */
		}
	argc -= optind;
	argv += optind;

	if (!(!mflag - !ifindex) || !pflag || argc) {
		usage();
		/* NOTREACHED */
	}

	if ((s = socket(PF_INET, SOCK_RAW, IPPROTO_DIVERT)) == -1) {
		err(1, "can't create divert socket");
		/* NOTREACHED */
	}

	bzero(&sin, sizeof(sin));
	sin.sin_family = PF_INET;
	sin.sin_addr.s_addr = INADDR_ANY;
	sin.sin_port = port;

	if (bind(s, (struct sockaddr *)&sin, sizeof(sin)) == -1) {
		err(1, "can't bind divert socket");
		/* NOTREACHED */
	}

	if (ifindex)
		if ((rtsock = socket(PF_ROUTE, SOCK_RAW, 0)) == -1) {
			err(1, "can't create routing socket");
			/* NOTREACHED */
		}

	maxmss = MAXMSS(mtu);
	if (verbose)
		fprintf(stderr, "Maximum MSS: %u\n", maxmss);

	if (!verbose)
		if (daemon(0, 0) == -1) {
			err(1, "can't daemonize");
			/* NOTREACHED */
		}

	if (ifindex) {
		FILE *pidfile;

		pidfile = fopen(pidfilename, "w");
		if (pidfile != NULL) {
			fprintf(pidfile, "%d\n", (int)getpid());
			fclose(pidfile);
			if (signal(SIGTERM, sigterm_handler) == SIG_ERR) {
				err(1, "can't install SIGTERM handler");
				/* NOTREACHED */
			}
		}
	}

	while (1) {
		FD_ZERO(&fdset);
		FD_SET(s, &fdset);
		if (rtsock != -1)
			FD_SET(rtsock, &fdset);

		if (select(32, &fdset, (fd_set *)NULL, (fd_set *)NULL, (struct timeval *)NULL) == -1) {
			warn("select failed");
			continue;
		}

		if (rtsock != -1 && FD_ISSET(rtsock, &fdset)) {
			struct if_msghdr ifm;

			if ((pktlen = read(rtsock, &ifm, sizeof(ifm))) == -1) {
				warn("read from routing socket failed");
				continue;
			}
			if (ifm.ifm_version != RTM_VERSION) {
				if (verbose)
					warnx("routing message version %d "
					      "not understood", ifm.ifm_version);
				continue;
			}
			if (ifm.ifm_type != RTM_IFINFO ||
			    ifm.ifm_index != ifindex)
				continue;
			if (mtu != ifm.ifm_data.ifi_mtu) {
				mtu = ifm.ifm_data.ifi_mtu;
				maxmss = MAXMSS(mtu);
				if (verbose)
					fprintf(stderr, "Maximum MSS: %u\n", maxmss);
			}
		}

		if (FD_ISSET(s, &fdset)) {
			sinlen = sizeof(sin);

			if ((pktlen = recvfrom(s, pkt, sizeof(pkt), 0,
					       (struct sockaddr *)&sin, &sinlen)) == -1)
				if (errno != EINTR) {
					warn("read from divert socket failed");
					continue;
				}

			hlen = pip->ip_hl << 2;

			/*-
			 * Check for MSS option only for outgoing
			 * TCP packets with zero fragment offset
			 * and correct total and header lengths.
			 */
			if ((both || sin.sin_addr.s_addr == INADDR_ANY) &&
			    pip->ip_p == IPPROTO_TCP &&
			    (ntohs(pip->ip_off) & IP_OFFMASK) == 0 &&
			    ntohs(pip->ip_len) == pktlen &&
			    hlen <= pktlen &&
			    pktlen - hlen >= sizeof(struct tcphdr))
				correct_mss((struct tcphdr *)(pkt + hlen),
					    pktlen - hlen, maxmss);

			if (sendto(s, pkt, pktlen, 0,
			    (struct sockaddr *)&sin, sinlen) == -1)
				warn("write to divert socket failed");
		}
	}
}


/*-
 * The following macro is used to update an
 * internet checksum.  "acc" is a 32-bit
 * accumulation of all the changes to the
 * checksum (adding in old 16-bit words and
 * subtracting out new words), and "cksum"
 * is the checksum value to be updated.
 */
#define ADJUST_CHECKSUM(acc, cksum) { \
	acc += cksum; \
	if (acc < 0) { \
		acc = -acc; \
		acc = (acc >> 16) + (acc & 0xffff); \
		acc += acc >> 16; \
		cksum = (u_short) ~acc; \
	} else { \
		acc = (acc >> 16) + (acc & 0xffff); \
		acc += acc >> 16; \
		cksum = (u_short) acc; \
	} \
}


void
correct_mss(struct tcphdr *tc, ssize_t pktlen, u_int16_t maxmss)
{
	int hlen, olen, optlen;
	u_char *opt;
	u_int16_t *mss;
	int accumulate;

	hlen = tc->th_off << 2;

	/* Invalid header length or header without options. */
	if (hlen <= sizeof(struct tcphdr) || hlen > pktlen)
		return;

	/* MSS option only allowed within SYN packets. */
	if (!(tc->th_flags & TH_SYN))
		return;

	for (olen = hlen - sizeof(struct tcphdr), opt = (u_char *)(tc + 1);
	     olen > 0; olen -= optlen, opt += optlen) {
		if (*opt == TCPOPT_EOL)
			break;
		else if (*opt == TCPOPT_NOP)
			optlen = 1;
		else {
			optlen = *(opt + 1);
			if (optlen <= 0 || optlen > olen)
				break;
			if (*opt == TCPOPT_MAXSEG) {
				if (optlen != TCPOLEN_MAXSEG)
					continue;
				mss = (u_int16_t *)(opt + 2);
				if (ntohs(*mss) > maxmss) {
					if (verbose)
						fprintf(stderr,
							"MSS: %u -> %u\n",
							ntohs(*mss), maxmss);
					accumulate = *mss;
					*mss = htons(maxmss);
					accumulate -= *mss;
					ADJUST_CHECKSUM(accumulate, tc->th_sum);
				}
			}
		}
	}
}


static int
if_mtu(const char *ifn, u_long *mtu)
{
	size_t needed;
	int mib[6];
	char *buf, *lim, *next;
	struct if_msghdr *ifm;
	struct sockaddr_dl *sdl;
	int ifindex;

	mib[0] = CTL_NET;
	mib[1] = PF_ROUTE;
	mib[2] = 0;
	mib[3] = AF_INET;	/* Only IP addresses please. */
	mib[4] = NET_RT_IFLIST;
	mib[5] = 0;		/* List all interfaces. */
/*
 * Get interface data.
 */
	if (sysctl(mib, 6, NULL, &needed, NULL, 0) == -1)
		err(1, "iflist-sysctl-estimate");
	if ((buf = malloc(needed)) == NULL)
		errx(1, "malloc failed");
	if (sysctl(mib, 6, buf, &needed, NULL, 0) == -1)
		err(1, "iflist-sysctl-get");
	lim = buf + needed;
/*
 * Loop through interfaces until one with
 * given name is found. This is done to
 * find correct interface index for routing
 * message processing.
 */
	ifindex = 0;
	next = buf;
	while (next < lim) {
		ifm = (struct if_msghdr *)next;
		next += ifm->ifm_msglen;
		if (ifm->ifm_version != RTM_VERSION) {
			if (verbose)
				warnx("routing message version %d "
				      "not understood", ifm->ifm_version);
			continue;
		}
		if (ifm->ifm_type == RTM_IFINFO) {
			sdl = (struct sockaddr_dl *)(ifm + 1);
			if (strlen(ifn) == sdl->sdl_nlen &&
			    strncmp(ifn, sdl->sdl_data, sdl->sdl_nlen) == 0) {
				*mtu = ifm->ifm_data.ifi_mtu;
				ifindex = ifm->ifm_index;
				break;
			}
		}
	}
	free(buf);
	return (ifindex);
}


static void
sigterm_handler(int sig)
{

	(void)unlink(pidfilename);
	exit(0);
}


void
usage(void)
{

	fprintf(stderr, "usage: tcpmssd [-v] -p port {-i iface | -m mtu}\n");
	exit(1);
}
