--- bsd/kernel.cc.orig	2006-02-18 08:36:06.000000000 +0100
+++ bsd/kernel.cc	2008-12-15 15:46:05.000000000 +0100
@@ -54,6 +54,7 @@
 #endif
 
 #ifdef HAVE_DEVSTAT
+#include <sys/dkstat.h>
 #include <devstat.h>
 #include <stdlib.h>	/*  For malloc().  */
 void DevStat_Init();
@@ -83,6 +84,10 @@
 #else
 #include <sys/dkstat.h>
 #endif
+#if defined(XOSVIEW_FREEBSD) && (__FreeBSD_version >= 700000)
+#include <sys/resource.h>
+#include <sys/sysctl.h>
+#endif
 
 #ifdef HAVE_SWAPCTL
 #include <unistd.h>		/*  For swapctl proto.  */
@@ -135,7 +140,7 @@
 // this later on.  This keeps the indices within the nlist constant.
 #define DUMMY_SYM "dummy_sym"
 
-#if defined(XOSVIEW_BSDI) || (defined(XOSVIEW_NETBSD) && (__NetBSD_Version__ >= 104260000))
+#if defined(XOSVIEW_BSDI) || (defined(XOSVIEW_NETBSD) && (__NetBSD_Version__ >= 104260000)) || (defined(XOSVIEW_FREEBSD) && (__FreeBSD_version >= 700000))
 // BSDI and __NetBSD_Version__ >= 104260000 reads cp_time through sysctl
 { DUMMY_SYM },
 #define DUMMY_0
@@ -211,19 +216,28 @@
 
 { "_bufspace" },
 #define BUFSPACE_SYM_INDEX      3
+#if __FreeBSD_version < 500000
 { "_intr_countp" },
 #define INTRCOUNTP_SYM_INDEX 	4
+{ DUMMY_SYM },
+#define DUMMY_5			5
+#else
+{ "_intrnames" },
+#define INTRNAMES_SYM_INDEX 	4
+{ "_eintrnames" },
+#define EINTRNAMES_SYM_INDEX 	5
+#endif /* FreeBSD < 5.x */
 { "_intrcnt" },
-#define INTRCNT_SYM_INDEX 	5
+#define INTRCNT_SYM_INDEX 	6
 { "_eintrcnt" },
-#define EINTRCNT_SYM_INDEX 	6
+#define EINTRCNT_SYM_INDEX 	7
 
 #ifndef HAVE_DEVSTAT
 
 { "_dk_ndrive" },
-#define DK_NDRIVE_SYM_INDEX     7
+#define DK_NDRIVE_SYM_INDEX     8
 { "_dk_wds" },
-#define DK_WDS_SYM_INDEX        8
+#define DK_WDS_SYM_INDEX        9
 
 #endif /*HAVE_DEVSTAT */
 
@@ -329,7 +343,12 @@
   while (nlp && nlp->n_name && strncmp(nlp->n_name, DUMMY_SYM, strlen(DUMMY_SYM))) {
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
@@ -402,11 +421,17 @@
 #if defined(XOSVIEW_NETBSD) && (__NetBSD_Version__ >= 104260000)
   static int mib[] = { CTL_KERN, KERN_CP_TIME };
 #endif
+#if defined(XOSVIEW_FREEBSD) && (__FreeBSD_version >= 700000)
+
+  long cpu[CPUSTATES];
+  size_t size = sizeof(cpu);
+
+#endif
 
   if (!timeArray) errx (-1, "BSDGetCPUTimes():  passed pointer was null!\n");
   if (CPUSTATES != 5)
     errx (-1, "Error:  xosview for *BSD expects 5 cpu states!\n");
-#if defined(__NetBSD_Version__) && __NetBSD_Version__ > 104260000 /* > 1.4Z */
+#if (defined(__NetBSD_Version__) && __NetBSD_Version__ > 104260000) /* > 1.4Z */
   struct schedstate_percpu ssp;
   size_t size = sizeof(ssp.spc_cp_time);
   if (sysctl(mib, 2, ssp.spc_cp_time, &size, NULL, 0) < 0) {
@@ -423,9 +448,18 @@
   }
   bcopy (cpu.cp_time,timeArray,sizeof (long) * CPUSTATES);
 #else
+#if defined(XOSVIEW_FREEBSD) && (__FreeBSD_version >= 700000)
+
+  if (sysctlbyname("kern.cp_time", &cpu, &size, NULL, 0) < 0) {
+    fprintf(stderr, "xosview: sysctl failed: %s\n", strerror(errno));
+    bzero(&cpu, sizeof(cpu));
+  }
+  bcopy (cpu,timeArray,sizeof (long) * CPUSTATES);
+#else
   safe_kvm_read_symbol (CP_TIME_SYM_INDEX, timeArray, sizeof (long) * CPUSTATES);
 #endif
 #endif
+#endif
 }
 
 
@@ -597,13 +631,21 @@
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
@@ -618,7 +660,11 @@
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
@@ -630,7 +676,11 @@
 
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
@@ -645,13 +695,18 @@
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
 		       NULL, 0,
 		       select_mode, 10, 0) == -1)
 		nodisk++;
+
 }
 
 int
@@ -672,7 +727,11 @@
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
@@ -680,7 +739,11 @@
 
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
@@ -704,14 +767,22 @@
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
 
@@ -725,12 +796,15 @@
 
 			di = dev_select[dn].position;
 
+#if __FreeBSD_version >= 500000
+			if (devstat_compute_statistics(&cur.dinfo->devices[di],
+#else
 			if (compute_stats(&cur.dinfo->devices[di],
+#endif
 				  &last.dinfo->devices[di], busy_seconds,
-				  &total_bytes, &total_transfers,
-				  NULL, NULL,
-				  NULL, NULL, 
-				  NULL, NULL)!= 0)
+				  DSM_TOTAL_BYTES, &total_bytes,
+				  DSM_TOTAL_TRANSFERS, &total_transfers,
+				  DSM_NONE)!= 0)
 				  break;
 			total_xfers += (int)total_transfers;
 			total_xbytes += (int)total_bytes;
@@ -740,7 +814,11 @@
 		last.dinfo = cur.dinfo;
 		cur.dinfo = tmp_dinfo;
 
+#if __FreeBSD_version >= 500000
+		last.snap_time = cur.snap_time;
+#else
 		last.busy_time = cur.busy_time;
+#endif
 
 	} else {
 		/* no disks found ? */
@@ -912,25 +990,26 @@
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
+#if __FreeBSD_version < 500000
     /* FreeBSD has an array of interrupt counts, indexed by device number.
        These are also indirected by IRQ num with intr_countp: */
     safe_kvm_read (nlst[INTRCOUNTP_SYM_INDEX].n_value,
@@ -944,6 +1023,46 @@
 	    sizeof(unsigned long);
 	intrCount[i] = kvm_intrcnt[idx];
     }
+#else /* FreeBSD 5.x and 6.x */
+    /* This code is stolen from vmstat */
+    unsigned long *kvm_intrcnt, *base_intrcnt;
+    char *kvm_intrname, *base_intrname;
+    size_t inamlen, intrcntlen;
+    unsigned int i, nintr;
+    int d;
+
+    intrcntlen = (nlst[EINTRCNT_SYM_INDEX].n_value - nlst[INTRCNT_SYM_INDEX].n_value);
+    inamlen = nlst[EINTRNAMES_SYM_INDEX].n_value - nlst[INTRNAMES_SYM_INDEX].n_value;
+    nintr = intrcntlen / sizeof(unsigned long);
+
+    if (((kvm_intrcnt = (unsigned long *)malloc(intrcntlen)) == NULL) || 
+	((kvm_intrname = (char *)malloc(inamlen)) == NULL))
+      err(1, "malloc()");
+
+    // keep track of the mem we're given:
+    base_intrcnt = kvm_intrcnt;
+    base_intrname = kvm_intrname;
+
+    safe_kvm_read (nlst[INTRCNT_SYM_INDEX].n_value, kvm_intrcnt, intrcntlen);
+    safe_kvm_read (nlst[INTRNAMES_SYM_INDEX].n_value, kvm_intrname, inamlen);
+
+    /* kvm_intrname has the ASCII names of the IRQs, every null-terminated
+     * string corresponds to a value in the kvm_intrcnt array */
+    for (i=0; i < nintr; i++) {
+	if (kvm_intrname[0] != '\0' && (*kvm_intrcnt != 0)) {
+	  /* Figure out which irq we have here */
+	    if (1 == sscanf(kvm_intrname, "irq%d:", &d))
+	      if (d < NUM_INTR)
+		intrCount[d] = *kvm_intrcnt;
+	}
+	kvm_intrcnt++;
+	kvm_intrname += strlen(kvm_intrname) + 1;
+    }
+
+    // Doh! somebody needs to free this stuff too... (pavel 20-Jan-2006)
+    free(base_intrcnt);
+    free(base_intrname);
+#endif
 #elif defined (XOSVIEW_BSDI)
     int nintr = 16;
 #if _BSDI_VERSION >= 199802 /* BSD/OS 4.x */
