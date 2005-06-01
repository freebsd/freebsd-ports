--- sysinfo.c.orig	Tue Oct  6 07:21:18 1998
+++ sysinfo.c	Thu May 12 15:49:32 2005
@@ -13,7 +13,9 @@
 #include <sys/ioctl_compat.h>	/* XXX NTTYDISC is too well hidden */
 #include <sys/tty.h>
 #include <sys/conf.h>
+#if __FreeBSD_version < 400000
 #include <sys/rlist.h>
+#endif
 #include <sys/sysctl.h>
 #include <sys/socket.h>
 #include <err.h>
@@ -34,8 +36,14 @@
 #include <sys/time.h>
 #include <sys/mount.h>
 #include <nfs/rpcv2.h>
+#if __FreeBSD_version >= 500000
+#include <nfs/nfsproto.h>
+#include <nfsclient/nfs.h>
+#include <nfsserver/nfsrvstats.h>
+#else
 #include <nfs/nfsv2.h>
 #include <nfs/nfs.h>
+#endif
 #include <osreldate.h>
 #include <fcntl.h>
 
@@ -95,6 +103,9 @@
 #endif /* HAVE_DEVSTAT */
 
 static struct nfsstats nfsstats;
+#if __FreeBSD_version >= 500000
+static struct nfsrvstats nfsrvstats;
+#endif
 static struct _nfsStats {
     int nfsServer, nfsClient;
 } nfsStats, old_nfsStats;
@@ -102,6 +113,7 @@
 struct nlist	nl[] = {
 #define	X_CP_TIME	0
 	{ "_cp_time" },
+#if __FreeBSD_version < 400000
 #define VM_SWAPLIST	1
 	{ "_swaplist" },/* list of free swap areas */
 #define VM_SWDEVT	2
@@ -129,6 +141,32 @@
 #define X_DKXFER        12
         { "_dk_xfer" },
 #endif
+#else /* __FreeBSD_version < 400000 */
+#define VM_DMMAX	1
+	{ "_dmmax" },	/* maximum size of a swap block */
+#define	V_MOUNTLIST	2
+	{ "_mountlist" },	/* address of head of mount list. */
+#define V_NUMV		3
+	{ "_numvnodes" },
+#define	FNL_NFILE	4
+/* nfiles changes name to openfiles near this FreeBSD version */
+#if __FreeBSD_version > 503101
+	{"_openfiles"},
+#else
+	{"_nfiles"},
+#endif
+#define FNL_MAXFILE	5
+	{"_maxfiles"},
+#define NLMANDATORY FNL_MAXFILE	/* names up to here are mandatory */
+#define X_CNT           6
+	{ "_cnt" },                /* struct vmmeter cnt */
+#define N_IFNET         7
+        { "_ifnet" },
+#ifndef HAVE_DEVSTAT
+#define X_DKXFER        8
+        { "_dk_xfer" },
+#endif
+#endif /* __FreeBSD_version < 400000 */
 	{ "" },
 };
 
@@ -238,6 +276,14 @@
 	int pkt_in_out;
 	int total_xfers=0;
 	int mib[3], size;
+#if __FreeBSD_version >= 500000
+	int rvsize;
+	struct xvfsconf vfc;
+#else
+#if (__FreeBSD_version >= 300004)
+    struct vfsconf vfc;
+#endif
+#endif // #if __FreeBSD_version >= 500000
 
 	/* NPROCS=0, CPU */
   if (cpuflag) {
@@ -356,19 +402,30 @@
 	for (i=0; i<10; i++)
 	    states[i] = 0;
 	size = sizeof(nfsstats);
+#if __FreeBSD_version >= 500000
+	rvsize = sizeof(nfsrvstats);
+#endif 
 #if (__FreeBSD_version < 199512)
 	mib[0] = CTL_FS;
 #else
 	mib[0] = CTL_VFS;
 #endif
-#if (__FreeBSD_version >= 300003) /* ?? */
-	mib[1] = MNT_EXPORTED;
+#if (__FreeBSD_version >= 300004)
+    if (getvfsbyname("nfs", &vfc) < 0)
+	/* no NFS in the kernel */
+	goto nfs_out;
+    mib[1] = vfc.vfc_typenum;
 #else
-	mib[1] = MNT_NFS;
+	mib[1] = MOUNT_NFS;
 #endif
 	mib[2] = NFS_NFSSTATS;
+#if __FreeBSD_version >= 500000
+	if (sysctl( mib, 3, &nfsstats, &size, NULL, 0) < 0 || sysctl( mib, 3, &nfsrvstats, &rvsize, NULL, 0) < 0)
+	    return;
+#else
 	if (sysctl( mib, 3, &nfsstats, &size, NULL, 0) < 0)
 	    goto nfs_out;
+#endif
 	else {
 	    old_nfsStats = nfsStats;
 
@@ -395,6 +452,22 @@
 #else
 				 nfsstats.rpccnt[NFSPROC_READDIR];
 #endif
+#if __FreeBSD_version >= 500000
+	    nfsStats.nfsServer = nfsrvstats.srvrpccnt[NFSPROC_GETATTR] + 
+	                         nfsrvstats.srvrpccnt[NFSPROC_SETATTR] +
+	                         nfsrvstats.srvrpccnt[NFSPROC_LOOKUP] +
+	                         nfsrvstats.srvrpccnt[NFSPROC_READLINK] +
+	                         nfsrvstats.srvrpccnt[NFSPROC_READ] +
+	                         nfsrvstats.srvrpccnt[NFSPROC_WRITE] +
+	                         nfsrvstats.srvrpccnt[NFSPROC_CREATE] +
+	                         nfsrvstats.srvrpccnt[NFSPROC_REMOVE] +
+	                         nfsrvstats.srvrpccnt[NFSPROC_RENAME] +
+	                         nfsrvstats.srvrpccnt[NFSPROC_LINK] +
+	                         nfsrvstats.srvrpccnt[NFSPROC_SYMLINK] +
+	                         nfsrvstats.srvrpccnt[NFSPROC_MKDIR] +
+	                         nfsrvstats.srvrpccnt[NFSPROC_RMDIR] + 
+				 nfsrvstats.srvrpccnt[NFSPROC_READDIR];
+#else
 	    nfsStats.nfsServer = nfsstats.srvrpccnt[NFSPROC_GETATTR] + 
 	                         nfsstats.srvrpccnt[NFSPROC_SETATTR] +
 	                         nfsstats.srvrpccnt[NFSPROC_LOOKUP] +
@@ -418,6 +491,7 @@
 #else
 				 nfsstats.srvrpccnt[NFSPROC_READDIR];
 #endif
+#endif // #if __FreeBSD_version >= 500000
 	}
 	scale_bar(250, nfsStats.nfsClient-old_nfsStats.nfsClient, 25, states, 0);
 	draw_bar(nfsflag-1, states, 10);
@@ -428,7 +502,7 @@
   }
 nfs_out:
 
-}
+;}
 
 
 /* swapmode is derived from freebsd's pstat source ...
@@ -438,6 +512,21 @@
 void
 swapmode(int *used, int *avail)
 {
+#if __FreeBSD_version >= 400000
+	/* based on swapmode from /usr/src/usr.bin/top/machine.c */
+	int n;
+	struct kvm_swap swapary[1];
+
+	n = kvm_getswapinfo(kd, swapary, 1, 0);
+	if (n < 0) {
+		*avail = *used = 0;
+		return;
+	}
+
+	*avail = swapary[0].ksw_total - swapary[0].ksw_used;
+	*used = swapary[0].ksw_used;
+	return;
+#else
 	char *header;
 	int hlen, nswap, nswdev, dmmax;
 	int i, div, nfree, npfree;
@@ -546,6 +635,7 @@
 	*used = *avail - nfree;
 	free(sw);
 	free(perdev);
+#endif /* __FreeBSD_version >= 400000 */
 }
 
 /*
@@ -623,13 +713,21 @@
 	 * Make sure that the userland devstat version matches the kernel
 	 * devstat version.
 	 */
+#if __FreeBSD_version >= 500000
+	if (devstat_checkversion(kd) < 0) {
+#else
 	if (checkversion() < 0) {
+#endif
 		nodisk++;
 		return;
 	}
 
 	/* find out how many devices we have */
+#if __FreeBSD_version >= 500000
+	if ((num_devices = devstat_getnumdevs(kd)) < 0) {
+#else
 	if ((num_devices = getnumdevs()) < 0) {
+#endif
 		nodisk++;
 		return;
 	}
@@ -644,7 +742,11 @@
 	 * changed here, since it almost certainly has.  We only look for
 	 * errors.
 	 */
+#if __FreeBSD_version >= 500000
+	if (devstat_getdevs(kd,&cur) == -1) {
+#else
 	if (getdevs(&cur) == -1) {
+#endif
 		nodisk++;
 		return;
 	}
@@ -656,7 +758,11 @@
 
 	/* only interested in disks */
 	matches = NULL;
+#if __FreeBSD_version >= 500000
+	if (devstat_buildmatch("da", &matches, &num_matches) != 0) {
+#else
 	if (buildmatch("da", &matches, &num_matches) != 0) {
+#endif
 		nodisk++;
 		return;
 	}
@@ -671,7 +777,11 @@
 	 * device list has changed, so we don't look for return values of 0
 	 * or 1.  If we get back -1, though, there is an error.
 	 */
+#if __FreeBSD_version >= 500000
+	if (devstat_selectdevs(&dev_select, &num_selected,
+#else
 	if (selectdevs(&dev_select, &num_selected,
+#endif
 		       &num_selections, &select_generation,
 		       generation, cur.dinfo->devices, num_devices,
 		       matches, num_matches,
@@ -697,7 +807,11 @@
 		 * the selection process again, in case a device that we
 		 * were previously displaying has gone away.
 		 */
+#if __FreeBSD_version >= 500000
+		switch (devstat_getdevs(kd,&cur)) {
+#else
 		switch (getdevs(&cur)) {
+#endif
 		case -1:
 			return (0);
 		case 1: {
@@ -705,7 +819,11 @@
 
 			num_devices = cur.dinfo->numdevs;
 			generation = cur.dinfo->generation;
+#if __FreeBSD_version >= 500000
+			retval = devstat_selectdevs(&dev_select, &num_selected,
+#else
 			retval = selectdevs(&dev_select, &num_selected,
+#endif
 					    &num_selections, &select_generation,
 					    generation, cur.dinfo->devices,
 					    num_devices, matches, num_matches,
@@ -729,14 +847,22 @@
 		 * Calculate elapsed time up front, since it's the same for all
 		 * devices.
 		 */
+#if __FreeBSD_version >= 500000
+		busy_seconds = cur.snap_time - last.snap_time;
+#else
 		busy_seconds = compute_etime(cur.busy_time, last.busy_time);
+#endif
 
 		/* this is the first time thru so just copy cur to last */
 		if (last.dinfo->numdevs == 0) {
 			tmp_dinfo = last.dinfo;
 			last.dinfo = cur.dinfo;
 			cur.dinfo = tmp_dinfo;
+#if __FreeBSD_version >= 500000
+			last.snap_time = cur.snap_time;
+#else
 			last.busy_time = cur.busy_time;
+#endif
 			return (0);
 		}
 
@@ -764,7 +890,11 @@
 		last.dinfo = cur.dinfo;
 		cur.dinfo = tmp_dinfo;
 
+#if __FreeBSD_version >= 500000
+		last.snap_time = cur.snap_time;
+#else
 		last.busy_time = cur.busy_time;
+#endif
 
 	} else
 		/* no disks found ? */
