--- bsd/kernel.cc.orig	Mon Jul 17 11:52:31 2000
+++ bsd/kernel.cc	Tue Aug 21 12:23:41 2001
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
@@ -828,25 +834,25 @@
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
@@ -875,8 +881,8 @@
       intrCount[i] = kvm_intrptrs[i];
 #endif /* _BSDI_VERSION */
 
-#else /* XOSVIEW_FREEBSD */
-  //  NetBSD/OpenBSD version, based on vmstat.c.  Note that the pc532
+#else /* XOSVIEW_FREEBSD & i386 */
+  //  NetBSD/OpenBSD & FreeBSD/Alpha version, based on vmstat.c.  Note that the pc532 
   //  platform does support intrcnt and eintrcnt, but vmstat uses
   //  the more advanced event counters to provide software
   //  counts.  We'll just use the intrcnt array here.  If anyone
