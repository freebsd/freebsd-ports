
$FreeBSD$

--- gmond/machines/freebsd.c.orig	Tue Jul 29 10:56:38 2003
+++ gmond/machines/freebsd.c	Mon Oct 27 17:02:26 2003
@@ -9,9 +9,11 @@
  */
 
 #include <kvm.h>
-#include <fcntl.h>
+
 #include <sys/param.h> 
+#include <sys/mount.h>
 #include <sys/sysctl.h>
+#include <sys/time.h>
 #include <sys/user.h>
 #if __FreeBSD_version < 500101
 #include <sys/dkstat.h>
@@ -20,12 +22,35 @@
 #endif
 #include <sys/stat.h>
 #include <vm/vm_param.h>
+
+#include <sys/socket.h>
+#include <net/if.h>
+#include <net/if_dl.h>
+#include <net/route.h>
+
 #include <unistd.h>
+#include <err.h>
+#include <fcntl.h>
+#include <limits.h>
+#include <paths.h>
+
+#include "dnet.h"
 #include "ganglia.h"
 #include "metric_typedefs.h"
 
 #define MIB_SWAPINFO_SIZE 3
 
+#ifndef MIN_NET_POLL_INTERVAL
+#define MIN_NET_POLL_INTERVAL 0.5
+#endif
+
+#ifndef UINT64_MAX
+#define UINT64_MAX	ULLONG_MAX
+#endif
+
+#define timertod(tvp) \
+    ((double)(tvp)->tv_sec + (double)(tvp)->tv_usec/(1000*1000))
+
 #ifndef XSWDEV_VERSION
 #define XSWDEV_VERSION  1
 struct xswdev {
@@ -37,14 +62,32 @@
 };
 #endif
 
+struct traffic {
+	uint64_t in_bytes;
+	uint64_t out_bytes;
+	uint64_t in_pkts;
+	uint64_t out_pkts;
+};
+
+static void get_netbw(double *, double *, double *, double *);
+static uint64_t counterdiff(uint64_t, uint64_t, uint64_t, uint64_t);
+
+
+static char	 *makenetvfslist(void);
+static size_t	  regetmntinfo(struct statfs **, long, const char **);
+static int	  checkvfsname(const char *, const char **);
+static const char **makevfslist(char *);
+static float	  find_disk_space(double *, double *);
+
 static int use_vm_swap_info = 0;
 static int mibswap[MIB_SWAPINFO_SIZE];
 static size_t mibswap_size;
 static kvm_t *kd = NULL;
 static int pagesize;
+static int	  skipvfs;
 
 /* Function prototypes */
-long percentages(int cnt, int *out, register long *new,
+static long percentages(int cnt, int *out, register long *new,
                           register long *old, long *diffs);
  
 /*
@@ -64,10 +107,25 @@
    if (sysctlnametomib("vm.swap_info", mibswap, &mibswap_size) == -1) {
       kd = kvm_open(NULL, NULL, NULL, O_RDONLY, "metric_init()");
    } else {
+      /*
+       * Versions of FreeBSD with the swap mib generally have a version
+       * of libkvm that doesn't need root for simple proc access so we
+       * just open /dev/null to give us a working handle here.  This is
+       * bogus, but only a few pre-release versions of 5.0 are
+       * affected by the bogosity and people running those should
+       * upgrade.
+       */
+      kd = kvm_open(_PATH_DEVNULL, NULL, NULL, O_RDONLY, "metric_init()");
       use_vm_swap_info = 1;
    }
    pagesize = getpagesize();
 
+   /*
+    * Call get_netbw once to initalize the counters.
+    */
+
+   get_netbw(NULL, NULL, NULL, NULL);
+
    val.int32 = SYNAPSE_SUCCESS;
    return val;
 }
@@ -124,7 +182,7 @@
    g_val_t val;
    struct kvm_swap swap[1];
    struct xswdev xsw;
-   size_t mibsize, size;
+   size_t size;
    int totswap, n;
    val.uint32 = 0;
    totswap = 0;
@@ -366,9 +424,41 @@
 g_val_t
 proc_run_func( void )
 {
+   struct kinfo_proc *kp;
+   int i;
+   int state;
+   int nentries;
+   int what = KERN_PROC_ALL;
    g_val_t val;
 
    val.uint32 = 0;
+
+   if (kd == NULL)
+      goto output;
+#ifdef KERN_PROC_NOTHREADS
+   what |= KERN_PROC_NOTHREADS
+#endif
+   if ((kp = kvm_getprocs(kd, what, 0, &nentries)) == 0 || nentries < 0)
+      goto output;
+
+   for (i = 0; i < nentries; kp++, i++) {
+#ifdef KINFO_PROC_SIZE
+      state = kp->ki_stat;
+#else
+      state = kp->kp_proc.p_stat;
+#endif
+      switch(state) {
+	 case SRUN:
+	 case SIDL:
+		val.uint32++;
+		break;
+      }
+   }
+
+   if (val.uint32 > 0)
+	val.uint32--;
+
+output:
    return val;
 }
 
@@ -461,7 +551,6 @@
    return val;
 }
 
-#include "dnet.h"
 
 static int
 find_mtu(const struct intf_entry *entry, void *arg)
@@ -509,8 +598,8 @@
  * $FreeBSD$
  */
 
-long percentages(int cnt, int *out, register long *new, 
-                          register long *old, long *diffs)  {
+static long percentages(int cnt, int *out, register long *new, 
+                        register long *old, long *diffs)  {
 
     register int i;
     register long change;
@@ -549,3 +638,563 @@
     return(total_change);
 }
 
+g_val_t
+pkts_in_func ( void )
+{
+   double in_pkts;
+   g_val_t val;
+
+   get_netbw(NULL, NULL, &in_pkts, NULL);
+
+   val.f = (float)in_pkts;
+   return val;
+}
+
+g_val_t
+pkts_out_func ( void )
+{
+   double out_pkts;
+   g_val_t val;
+
+   get_netbw(NULL, NULL, NULL, &out_pkts);
+
+   val.f = (float)out_pkts;
+   return val;
+}
+
+g_val_t
+bytes_out_func ( void )
+{
+   double out_bytes;
+   g_val_t val;
+
+   get_netbw(NULL, &out_bytes, NULL, NULL);
+
+   val.f = (float)out_bytes;
+   return val;
+}
+
+g_val_t
+bytes_in_func ( void )
+{
+   double in_bytes;
+   g_val_t val;
+
+   get_netbw(&in_bytes, NULL, NULL, NULL);
+
+   val.f = (float)in_bytes;
+   return val;
+}
+
+/*
+ * Disk space reporting functions from Linux code.  find_disk_space()
+ * body derived from FreeBSD df and mount code.
+ */
+
+g_val_t
+disk_free_func( void )
+{
+   double total_free=0.0;
+   double total_size=0.0;
+   g_val_t val;
+
+   find_disk_space(&total_size, &total_free);
+
+   val.d = total_free;
+   return val;
+}
+
+g_val_t
+disk_total_func( void )
+{
+   double total_free=0.0;
+   double total_size=0.0;
+   g_val_t val;
+
+   find_disk_space(&total_size, &total_free);
+
+   val.d = total_size;
+   return val;
+}
+
+g_val_t
+part_max_used_func( void )
+{
+   double total_free=0.0;
+   double total_size=0.0;
+   float most_full;
+   g_val_t val;
+
+   most_full = find_disk_space(&total_size, &total_free);
+
+   val.f = most_full;
+   return val;
+}
+
+
+/*
+ * Copyright (c) 1980, 1983, 1990, 1993, 1994, 1995
+ *	The Regents of the University of California.  All rights reserved.
+ * (c) UNIX System Laboratories, Inc.
+ * All or some portions of this file are derived from material licensed
+ * to the University of California by American Telephone and Telegraph
+ * Co. or Unix System Laboratories, Inc. and are reproduced herein with
+ * the permission of UNIX System Laboratories, Inc.
+ *
+ * Redistribution and use in source and binary forms, with or without
+ * modification, are permitted provided that the following conditions
+ * are met:
+ * 1. Redistributions of source code must retain the above copyright
+ *    notice, this list of conditions and the following disclaimer.
+ * 2. Redistributions in binary form must reproduce the above copyright
+ *    notice, this list of conditions and the following disclaimer in the
+ *    documentation and/or other materials provided with the distribution.
+ * 3. All advertising materials mentioning features or use of this software
+ *    must display the following acknowledgement:
+ *      This product includes software developed by the University of
+ *      California, Berkeley and its contributors.
+ * 4. Neither the name of the University nor the names of its contributors
+ *    may be used to endorse or promote products derived from this software
+ *    without specific prior written permission.
+ *
+ * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
+ * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
+ * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
+ * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
+ * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
+ * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
+ * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
+ * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
+ * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
+ * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
+ * SUCH DAMAGE.
+ *
+ *
+ * NOTE: The copyright of UC Berkeley's Berkeley Software Distribution
+ * ("BSD") source has been updated.  The copyright addendum may be found
+ * at ftp://ftp.cs.berkeley.edu/pub/4bsd/README.Impt.License.Change.
+ */
+
+
+
+static float
+find_disk_space(double *total, double *tot_avail)
+{
+	struct statfs *mntbuf;
+	const char *fstype;
+	const char **vfslist;
+	size_t i, mntsize;
+	size_t used, availblks;
+	const double reported_units = 1e9;
+	double toru;
+	float pct;
+	float most_full = 0.0;
+
+	*total = 0.0;
+	*tot_avail = 0.0;
+
+	fstype = "ufs";
+
+	vfslist = makevfslist(makenetvfslist());
+
+	mntsize = getmntinfo(&mntbuf, MNT_NOWAIT);
+	mntsize = regetmntinfo(&mntbuf, mntsize, vfslist);
+	for (i = 0; i < mntsize; i++) {
+		if ((mntbuf[i].f_flags & MNT_IGNORE) == 0) {
+			used = mntbuf[i].f_blocks - mntbuf[i].f_bfree;
+			availblks = mntbuf[i].f_bavail + used;
+			pct = (availblks == 0 ? 100.0 :
+			    (double)used / (double)availblks * 100.0);
+			if (pct > most_full)
+				most_full = pct;
+
+			toru = reported_units/mntbuf[i].f_bsize;
+			*total += mntbuf[i].f_blocks / toru;
+			*tot_avail += mntbuf[i].f_bavail / toru;
+		}
+	}
+
+	return most_full;
+}
+
+/*
+ * Make a pass over the file system info in ``mntbuf'' filtering out
+ * file system types not in vfslist and possibly re-stating to get
+ * current (not cached) info.  Returns the new count of valid statfs bufs.
+ */
+static size_t
+regetmntinfo(struct statfs **mntbufp, long mntsize, const char **vfslist)
+{
+	int i, j;
+	struct statfs *mntbuf;
+
+	if (vfslist == NULL)
+		return (getmntinfo(mntbufp, MNT_WAIT));
+
+	mntbuf = *mntbufp;
+	for (j = 0, i = 0; i < mntsize; i++) {
+		if (checkvfsname(mntbuf[i].f_fstypename, vfslist))
+			continue;
+		(void)statfs(mntbuf[i].f_mntonname,&mntbuf[j]);
+		j++;
+	}
+	return (j);
+}
+
+static int
+checkvfsname(vfsname, vfslist)
+	const char *vfsname;
+	const char **vfslist;
+{
+
+	if (vfslist == NULL)
+		return (0);
+	while (*vfslist != NULL) {
+		if (strcmp(vfsname, *vfslist) == 0)
+			return (skipvfs);
+		++vfslist;
+	}
+	return (!skipvfs);
+}
+
+static const char **
+makevfslist(fslist)
+	char *fslist;
+{
+	const char **av;
+	int i;
+	char *nextcp;
+
+	if (fslist == NULL)
+		return (NULL);
+	if (fslist[0] == 'n' && fslist[1] == 'o') {
+		fslist += 2;
+		skipvfs = 1;
+	}
+	for (i = 0, nextcp = fslist; *nextcp; nextcp++)
+		if (*nextcp == ',')
+			i++;
+	if ((av = malloc((size_t)(i + 2) * sizeof(char *))) == NULL) {
+		warnx("malloc failed");
+		return (NULL);
+	}
+	nextcp = fslist;
+	i = 0;
+	av[i++] = nextcp;
+	while ((nextcp = strchr(nextcp, ',')) != NULL) {
+		*nextcp++ = '\0';
+		av[i++] = nextcp;
+	}
+	av[i++] = NULL;
+	return (av);
+}
+
+static char *
+makenetvfslist(void)
+{
+#if __FreeBSD_version > 500000
+	char *str, *strptr, **listptr;
+	struct xvfsconf *xvfsp, *keep_xvfsp;
+	size_t buflen;
+	int cnt, i, maxvfsconf;
+
+	if (sysctlbyname("vfs.conflist", NULL, &buflen, NULL, 0) < 0) {
+		warn("sysctl(vfs.conflist)");
+		return (NULL);
+	}
+	xvfsp = malloc(buflen);
+	if (xvfsp == NULL) {
+		warnx("malloc failed");
+		return (NULL);
+	}
+	keep_xvfsp = xvfsp;
+	if (sysctlbyname("vfs.conflist", xvfsp, &buflen, NULL, 0) < 0) {
+		warn("sysctl(vfs.conflist)");
+		free(keep_xvfsp);
+		return (NULL);
+	}
+	maxvfsconf = buflen / sizeof(struct xvfsconf);
+
+	if ((listptr = malloc(sizeof(char*) * maxvfsconf)) == NULL) {
+		warnx("malloc failed");
+		free(keep_xvfsp);
+		return (NULL);
+	}
+
+	for (cnt = 0, i = 0; i < maxvfsconf; i++) {
+		if (xvfsp->vfc_flags & (VFCF_NETWORK|VFCF_SYNTHETIC|VFCF_LOOPBACK)) {
+			listptr[cnt++] = strdup(xvfsp->vfc_name);
+			if (listptr[cnt-1] == NULL) {
+				warnx("malloc failed");
+				free(listptr);
+				free(keep_xvfsp);
+				return (NULL);
+			}
+		}
+		xvfsp++;
+	}
+
+	if (cnt == 0 ||
+	    (str = malloc(sizeof(char) * (32 * cnt + cnt + 2))) == NULL) {
+		if (cnt > 0)
+			warnx("malloc failed");
+		free(listptr);
+		free(keep_xvfsp);
+		return (NULL);
+	}
+
+	*str = 'n'; *(str + 1) = 'o';
+	for (i = 0, strptr = str + 2; i < cnt; i++, strptr++) {
+		strncpy(strptr, listptr[i], 32);
+		strptr += strlen(listptr[i]);
+		*strptr = ',';
+		free(listptr[i]);
+	}
+	*(--strptr) = NULL;
+
+	free(keep_xvfsp);
+#else
+	char *str, *strptr, **listptr;
+	int mib[3], maxvfsconf, cnt=0, i;
+	size_t miblen;
+	struct ovfsconf *ptr;
+
+	mib[0] = CTL_VFS; mib[1] = VFS_GENERIC; mib[2] = VFS_MAXTYPENUM;
+	miblen=sizeof(maxvfsconf);
+	if (sysctl(mib, (unsigned int)(sizeof(mib) / sizeof(mib[0])),
+	    &maxvfsconf, &miblen, NULL, 0)) {
+		warnx("sysctl failed");
+		return (NULL);
+	}
+
+	if ((listptr = malloc(sizeof(char*) * maxvfsconf)) == NULL) {
+		warnx("malloc failed");
+		return (NULL);
+	}
+
+	for (ptr = getvfsent(); ptr; ptr = getvfsent())
+		if (ptr->vfc_flags & (VFCF_NETWORK|VFCF_SYNTHETIC|VFCF_LOOPBACK)) {
+			listptr[cnt++] = strdup(ptr->vfc_name);
+			if (listptr[cnt-1] == NULL) {
+				warnx("malloc failed");
+				return (NULL);
+			}
+		}
+
+	if (cnt == 0 ||
+	    (str = malloc(sizeof(char) * (32 * cnt + cnt + 2))) == NULL) {
+		if (cnt > 0)
+			warnx("malloc failed");
+		free(listptr);
+		return (NULL);
+	}
+
+	*str = 'n'; *(str + 1) = 'o';
+	for (i = 0, strptr = str + 2; i < cnt; i++, strptr++) {
+		strncpy(strptr, listptr[i], 32);
+		strptr += strlen(listptr[i]);
+		*strptr = ',';
+		free(listptr[i]);
+	}
+	*(--strptr) = NULL;
+
+#endif
+	free(listptr);
+	return (str);
+
+}
+
+static void
+get_netbw(double *in_bytes, double *out_bytes,
+    double *in_pkts, double *out_pkts)
+{
+#ifdef NETBW_DEBUG
+	char		name[IFNAMSIZ];
+#endif
+	struct		if_msghdr *ifm, *nextifm;
+	struct		sockaddr_dl *sdl;
+	char		*buf, *lim, *next;
+	size_t		needed;
+	int		mib[6];
+	int		i;
+	int		index;
+	static double	ibytes, obytes, ipkts, opkts;
+	struct timeval	this_time;
+	struct timeval	time_diff;
+	struct traffic	traffic;
+	static struct timeval last_time = {0,0};
+	static int	indexes = 0;
+	static int	*seen = NULL;
+	static struct traffic *lastcount = NULL;
+	static double	o_ibytes, o_obytes, o_ipkts, o_opkts;
+
+	ibytes = obytes = ipkts = opkts = 0.0;
+
+	mib[0] = CTL_NET;
+	mib[1] = PF_ROUTE;
+	mib[2] = 0;
+	mib[3] = 0;			/* address family */
+	mib[4] = NET_RT_IFLIST;
+	mib[5] = 0;		/* interface index */
+
+	gettimeofday(&this_time, NULL);
+	timersub(&this_time, &last_time, &time_diff);
+	if (timertod(&time_diff) < MIN_NET_POLL_INTERVAL) {
+		goto output;
+	}
+
+
+	if (sysctl(mib, 6, NULL, &needed, NULL, 0) < 0)
+		errx(1, "iflist-sysctl-estimate");
+	if ((buf = malloc(needed)) == NULL)
+		errx(1, "malloc");
+	if (sysctl(mib, 6, buf, &needed, NULL, 0) < 0)
+		errx(1, "actual retrieval of interface table");
+	lim = buf + needed;
+
+	next = buf;
+	while (next < lim) {
+
+		ifm = (struct if_msghdr *)next;
+		
+		if (ifm->ifm_type == RTM_IFINFO) {
+			sdl = (struct sockaddr_dl *)(ifm + 1);
+		} else {
+			fprintf(stderr, "out of sync parsing NET_RT_IFLIST\n");
+			fprintf(stderr, "expected %d, got %d\n", RTM_IFINFO,
+				ifm->ifm_type);
+			fprintf(stderr, "msglen = %d\n", ifm->ifm_msglen);
+			fprintf(stderr, "buf:%p, next:%p, lim:%p\n", buf, next,
+				lim);
+			exit (1);
+		}
+
+		next += ifm->ifm_msglen;
+		while (next < lim) {
+			nextifm = (struct if_msghdr *)next;
+
+			if (nextifm->ifm_type != RTM_NEWADDR)
+				break;
+
+			next += nextifm->ifm_msglen;
+		}
+
+		if ((ifm->ifm_flags & IFF_LOOPBACK) || 
+		    !(ifm->ifm_flags & IFF_UP))
+			continue;
+
+		index = ifm->ifm_index;
+
+		/* If we don't have a previous value yet, make a slot. */
+		if (index >= indexes) {
+			seen = realloc(seen, sizeof(*seen)*(index+1));
+			lastcount = realloc(lastcount,
+			    sizeof(*lastcount)*(index+1));
+
+			/* Initalize the new slots */
+			for (i = indexes; i <= index; i++) {
+				seen[i] = 0;
+			}
+			indexes = index+1;
+		}
+
+		/*
+		 * If this is the first time we've seen this interface,
+		 * set the last values to the current ones.  That causes
+		 * us to see no bandwidth on the interface the first
+		 * time, but that's OK.
+		 */
+		if (!seen[index]) {
+			seen[index] = 1;
+			lastcount[index].in_bytes = ifm->ifm_data.ifi_ibytes;
+			lastcount[index].out_bytes = ifm->ifm_data.ifi_obytes;
+			lastcount[index].in_pkts = ifm->ifm_data.ifi_ipackets;
+			lastcount[index].out_pkts = ifm->ifm_data.ifi_opackets;
+		}
+
+		traffic.in_bytes = counterdiff(lastcount[index].in_bytes,
+		    ifm->ifm_data.ifi_ibytes, ULONG_MAX, 0);
+		traffic.out_bytes = counterdiff(lastcount[index].out_bytes,
+		    ifm->ifm_data.ifi_obytes, ULONG_MAX, 0);
+		traffic.in_pkts = counterdiff(lastcount[index].in_pkts,
+		    ifm->ifm_data.ifi_ipackets, ULONG_MAX, 0);
+		traffic.out_pkts = counterdiff(lastcount[index].out_pkts,
+		    ifm->ifm_data.ifi_opackets, ULONG_MAX, 0);
+
+		lastcount[index].in_bytes = ifm->ifm_data.ifi_ibytes;
+		lastcount[index].out_bytes = ifm->ifm_data.ifi_obytes;
+		lastcount[index].in_pkts = ifm->ifm_data.ifi_ipackets;
+		lastcount[index].out_pkts = ifm->ifm_data.ifi_opackets;
+
+#ifdef NETBW_DEBUG
+		if_indextoname(index, name);
+		printf("%s: \n", name);
+		printf("\topackets=%llu ipackets=%llu\n",
+		    traffic.out_pkts, traffic.in_pkts);
+		printf("\tobytes=%llu ibytes=%llu\n",
+		    traffic.out_bytes, traffic.in_bytes);
+#endif
+
+		if (timerisset(&last_time)) {
+			ibytes += (double)traffic.in_bytes / timertod(&time_diff);
+			obytes += (double)traffic.out_bytes / timertod(&time_diff);
+			ipkts += (double)traffic.in_pkts / timertod(&time_diff);
+			opkts += (double)traffic.out_pkts / timertod(&time_diff);
+		}
+	}
+	free(buf);
+
+	/* Save the values from this time */
+	last_time = this_time;
+	o_ibytes = ibytes;
+	o_obytes = obytes;
+	o_ipkts = ipkts;
+	o_opkts = opkts;
+
+output:
+	if (in_bytes != NULL)
+		*in_bytes = o_ibytes;
+	if (out_bytes != NULL)
+		*out_bytes = o_obytes;
+	if (in_pkts != NULL)
+		*in_pkts = o_ipkts;
+	if (out_pkts != NULL)
+		*out_pkts = o_opkts;
+}
+
+static uint64_t
+counterdiff(uint64_t oldval, uint64_t newval, uint64_t maxval, uint64_t maxdiff)
+{
+	uint64_t diff;
+
+	if (maxdiff == 0)
+		maxdiff = maxval;
+
+	/* Paranoia */
+	if (oldval > maxval || newval > maxval)
+		return 0;
+
+	/*
+	 * Tackle the easy case.  Don't worry about maxdiff here because
+	 * we're SOL if it happens (i.e. assuming a reset just makes
+	 * matters worse).
+	 */
+	if (oldval <= newval)
+		return (newval - oldval);
+
+	/*
+         * Now the tricky part.  If we assume counters never get reset,
+         * this is easy.  Unfortunaly, they do get reset on some
+         * systems, so we need to try and deal with that.  Our huristic
+         * is that if out difference is greater then maxdiff and newval
+         * is less or equal to maxdiff, then we've probably been reset
+         * rather then actually wrapping.  Obviously, you need to be
+         * careful to poll often enough that you won't exceed maxdiff or
+         * you will get undersized numbers when you do wrap.
+	 */
+	diff = maxval - oldval + newval;
+	if (diff > maxdiff && newval <= maxdiff)
+		return newval;
+
+	return diff;
+}
