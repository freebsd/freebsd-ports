--- php_http.h.orig	Fri Jun  9 02:10:44 2006
+++ php_http.h	Sun Jun 11 17:06:51 2006
@@ -144,7 +144,11 @@
 #	define HTTP_G (&http_globals)
 #endif
 
-#define HTTP_HAVE_EXT(EXT) ((defined(HAVE_##EXT) || defined(HAVE_PHP_##EXT) || defined(HAVE_##EXT##_EXT)) && (HTTP_SHARED_DEPS || !defined(COMPILE_DL_##EXT)))
+#if defined(__GNUC__) && (__GNUC__ < 3)
+#	define HTTP_HAVE_EXT(EXT) 0
+#else
+#	define HTTP_HAVE_EXT(EXT) ((defined(HAVE_##EXT) || defined(HAVE_PHP_##EXT) || defined(HAVE_##EXT##_EXT)) && (HTTP_SHARED_DEPS || !defined(COMPILE_DL_##EXT)))
+#endif
 
 PHP_FUNCTION(http_test);
 PHP_FUNCTION(http_date);
