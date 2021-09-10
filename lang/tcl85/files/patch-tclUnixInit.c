--- tclUnixInit.c.orig	2015-10-23 11:50:57 UTC
+++ tclUnixInit.c
@@ -452,14 +452,6 @@ TclpInitPlatform(void)
 #endif /* SIGPIPE */
 
 #if defined(__FreeBSD__) && defined(__GNUC__)
-    /*
-     * Adjust the rounding mode to be more conventional. Note that FreeBSD
-     * only provides the __fpsetreg() used by the following two for the GNU
-     * Compiler. When using, say, Intel's icc they break. (Partially based on
-     * patch in BSD ports system from root@celsius.bychok.com)
-     */
-
-    fpsetround(FP_RN);
     (void) fpsetmask(0L);
 #endif
 
