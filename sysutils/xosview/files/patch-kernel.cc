--- bsd/kernel.cc.orig	Tue Oct  9 10:40:51 2001
+++ bsd/kernel.cc	Mon Oct 27 20:03:03 2003
@@ -46,6 +46,7 @@
 #endif
 
 #ifdef HAVE_DEVSTAT
+#include <sys/dkstat.h>
 #include <devstat.h>
 #include <stdlib.h>	/*  For malloc().  */
 void DevStat_Init();
@@ -297,7 +298,12 @@
   while (nlp && nlp->n_name) {
     if ((nlp->n_type == 0) || (nlp->n_value == 0))
       /*errx (-1, "kvm_nlist() lookup failed for symbol '%s'.", nlp->n_name);*/
+#if defined(XOSVIEW_FREEBSD) && defined(__alpha__)
+	/* XXX: this should be properly fixed. */
+	;
+#else
       warnx ("kvm_nlist() lookup failed for symbol '%s'.", nlp->n_name);
+#endif
     nlp++;
   }
 #ifdef HAVE_DEVSTAT
@@ -493,7 +499,7 @@
 //
 
 void
-BSDGetSwapCtlInfo(int *totalp, int *freep) {
+BSDGetSwapCtlInfo(int64_t *totalp, int64_t *freep) {
   int	totalinuse, totalsize;
   int rnswap, nswap = swapctl(SWAP_NSWAP, 0, 0);
   struct swapent *swapiter;
@@ -557,13 +563,21 @@
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
@@ -578,7 +592,11 @@
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
@@ -590,7 +608,11 @@
 
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
@@ -605,7 +627,11 @@
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
@@ -632,7 +658,11 @@
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
@@ -640,7 +670,11 @@
 
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
@@ -664,14 +698,22 @@
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
 
@@ -685,7 +727,11 @@
 
 			di = dev_select[dn].position;
 
+#if __FreeBSD_version >= 500000
+			if (devstat_compute_statistics(&cur.dinfo->devices[di],
+#else
 			if (compute_stats(&cur.dinfo->devices[di],
+#endif
 				  &last.dinfo->devices[di], busy_seconds,
 				  &total_bytes, &total_transfers,
 				  NULL, NULL,
@@ -700,7 +746,11 @@
 		last.dinfo = cur.dinfo;
 		cur.dinfo = tmp_dinfo;
 
+#if __FreeBSD_version >= 500000
+		last.snap_time = cur.snap_time;
+#else
 		last.busy_time = cur.busy_time;
+#endif
 
 	} else {
 		/* no disks found ? */
@@ -828,25 +878,25 @@
   OpenKDIfNeeded(); 
   nintr = (nlst[EINTRCNT_SYM_INDEX].n_value -
 	   nlst[INTRCNT_SYM_INDEX].n_value)   / sizeof(int);
-#ifdef XOSVIEW_FREEBSD
-  /*  I'm not sure exactly how FreeBSD does things, but just do
+#if defined(i386)
+# if defined(XOSVIEW_FREEBSD)
+  /*  I'm not sure exactly how FreeBSD/i386 does things, but just do
    *  16 for now.  bgrayson  */
   return 16;
-#else
-# if defined(i386)
+# else
   /*  On the 386 platform, we count stray interrupts between
    *  intrct and eintrcnt, also, but we don't want to show these.  */
   return nintr/2;
-# else
-  return nintr;
 # endif
+#else
+  return nintr;
 #endif
 }
 #endif /* XOSVIEW_OPENBSD */
 
 void
 BSDGetIntrStats (unsigned long intrCount[NUM_INTR]) {
-#ifdef XOSVIEW_FREEBSD
+#if defined(XOSVIEW_FREEBSD) && defined(__i386__)
     /* FreeBSD has an array of interrupt counts, indexed by device number.
        These are also indirected by IRQ num with intr_countp: */
     safe_kvm_read (nlst[INTRCOUNTP_SYM_INDEX].n_value,
@@ -875,8 +925,8 @@
       intrCount[i] = kvm_intrptrs[i];
 #endif /* _BSDI_VERSION */
 
-#else /* XOSVIEW_FREEBSD */
-  //  NetBSD/OpenBSD version, based on vmstat.c.  Note that the pc532
+#else /* XOSVIEW_FREEBSD & i386 */
+  //  NetBSD/OpenBSD & FreeBSD/Alpha version, based on vmstat.c.  Note that the pc532 
   //  platform does support intrcnt and eintrcnt, but vmstat uses
   //  the more advanced event counters to provide software
   //  counts.  We'll just use the intrcnt array here.  If anyone
