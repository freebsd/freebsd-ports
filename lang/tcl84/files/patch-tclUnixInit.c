--- tclUnixInit.c.orig	2012-11-19 16:27:16 UTC
+++ tclUnixInit.c
@@ -268,14 +268,6 @@ TclpInitPlatform()
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
     fpsetmask(0L);
 #endif
 
