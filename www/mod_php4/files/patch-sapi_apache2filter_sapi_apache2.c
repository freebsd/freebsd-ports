--- sapi/apache2filter/sapi_apache2.c.orig	Mon May  6 17:42:23 2002
+++ sapi/apache2filter/sapi_apache2.c	Mon Aug 12 22:49:58 2002
@@ -531,8 +531,8 @@
 	ap_hook_post_config(php_apache_server_startup, NULL, NULL, APR_HOOK_MIDDLE);
 	ap_hook_insert_filter(php_insert_filter, NULL, NULL, APR_HOOK_MIDDLE);
     ap_hook_post_read_request(php_post_read_request, NULL, NULL, APR_HOOK_MIDDLE);
-	ap_register_output_filter("PHP", php_output_filter, AP_FTYPE_RESOURCE);
-	ap_register_input_filter("PHP", php_input_filter, AP_FTYPE_RESOURCE);
+	ap_register_output_filter("PHP", php_output_filter, NULL, AP_FTYPE_RESOURCE);
+	ap_register_input_filter("PHP", php_input_filter, NULL, AP_FTYPE_RESOURCE);
 }
 
 AP_MODULE_DECLARE_DATA module php4_module = {
