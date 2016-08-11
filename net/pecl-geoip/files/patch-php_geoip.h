--- php_geoip.h.orig	2014-05-01 17:44:31 UTC
+++ php_geoip.h
@@ -26,6 +26,10 @@ extern zend_module_entry geoip_module_en
 
 #define PHP_GEOIP_VERSION "1.1.0"
 
+#if PHP_MAJOR_VERSION < 7
+typedef long zend_long;
+#endif
+
 #ifdef PHP_WIN32
 #define PHP_GEOIP_API __declspec(dllexport)
 #else
