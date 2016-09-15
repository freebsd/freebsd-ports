--- unix/tclUnixInit.c.orig    2016-09-08 20:22:10.064101000 -0400
+++ unix/tclUnixInit.c 2016-09-08 20:22:42.345592000 -0400
@@ -391,14 +391,6 @@
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
 
