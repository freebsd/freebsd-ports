--- tests/test_args_to_config.c.orig	2013-01-26 18:31:02.000000000 -0800
+++ tests/test_args_to_config.c	2013-01-26 18:40:07.000000000 -0800
@@ -123,7 +123,13 @@
 	int rc;
 
 	ykp_errno = 0;
-	optind = 0; /* getopt reinit */
+
+/* Handle both GNU and BSD getopt reinit */
+#ifdef __GLIBC__
+	optind = 0;
+#else
+	optind = optreset = 1;
+#endif
 
 	/* copy version number from st into cfg */
 	assert(ykp_configure_for(cfg, 1, st) == 1);
@@ -308,7 +314,13 @@
 	int argc = 7;
 
 	ykp_errno = 0;
-	optind = 0; /* getopt reinit */
+
+/* Handle both GNU and BSD getopt reinit */
+#ifdef __GLIBC__
+	optind = 0;
+#else
+	optind = optreset = 1;
+#endif
 
 	/* copy version number from st into cfg */
   ykp_configure_version(cfg, st);
