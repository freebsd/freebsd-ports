--- imap/cyr_virusscan.c.orig	2018-08-10 02:59:00 UTC
+++ imap/cyr_virusscan.c
@@ -193,8 +193,17 @@ int clamav_scanfile(void *state, const c
     int r;
 
     /* scan file */
+#ifdef CL_SCAN_STDOPT
     r = cl_scanfile(fname, virname, NULL, st->av_engine,
                     CL_SCAN_STDOPT);
+#else
+    static struct cl_scan_options options;
+
+    memset(&options, 0, sizeof(struct cl_scan_options));
+    options.parse |= ~0; /* enable all parsers */
+
+    r = cl_scanfile(fname, virname, NULL, st->av_engine, &options);
+#endif
 
     switch (r) {
     case CL_CLEAN:
