--- src/ftwin.c.orig	2009-05-21 14:32:32.000000000 +0200
+++ src/ftwin.c	2013-09-05 08:21:38.056133246 +0200
@@ -228,7 +228,7 @@
     apr_dir_t *dir;
     apr_int32_t statmask =
 	APR_FINFO_SIZE | APR_FINFO_TYPE | APR_FINFO_USER | APR_FINFO_GROUP | APR_FINFO_UPROT | APR_FINFO_GPROT;
-    apr_size_t fname_len;
+    apr_size_t fname_len = 0;
     apr_uint32_t hash_value;
     apr_status_t status;
     int rc;
