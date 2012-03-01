--- ./libopendkim/tests/t-test75.c.orig	2012-03-01 08:52:30.000000000 +0900
+++ ./libopendkim/tests/t-test75.c	2012-03-01 15:50:21.000000000 +0900
@@ -52,6 +52,14 @@
 	dkim_query_t qtype = DKIM_QUERY_FILE;
 	unsigned char hdr[MAXHEADER + 1];
 
+#ifdef USE_GNUTLS
+	(void) gnutls_global_init();
+#endif /* USE_GNUTLS */
+
+	/* instantiate the library */
+	lib = dkim_init(NULL, NULL);
+	assert(lib != NULL);
+
 	if (!dkim_libfeature(lib, DKIM_FEATURE_PARSE_TIME))
 	{
 		printf("*** Date: value extraction SKIPPED\n");
@@ -62,14 +70,6 @@
 		printf("*** Date: value extraction\n");
 	}
 
-#ifdef USE_GNUTLS
-	(void) gnutls_global_init();
-#endif /* USE_GNUTLS */
-
-	/* instantiate the library */
-	lib = dkim_init(NULL, NULL);
-	assert(lib != NULL);
-
 #ifdef TEST_KEEP_FILES
 	/* set flags */
 	flags = (DKIM_LIBFLAGS_TMPFILES|DKIM_LIBFLAGS_KEEPFILES);
