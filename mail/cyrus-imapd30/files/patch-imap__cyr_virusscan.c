--- imap/cyr_virusscan.c.orig	2019-03-15 00:31:20 UTC
+++ imap/cyr_virusscan.c
@@ -193,7 +193,7 @@ int clamav_scanfile(void *state, const c
     int r;
 
     /* scan file */
-#if LIBCLAMAV_MAJORVER < 9
+#ifdef CL_SCAN_STDOPT
     r = cl_scanfile(fname, virname, NULL, st->av_engine,
                     CL_SCAN_STDOPT);
 #else
