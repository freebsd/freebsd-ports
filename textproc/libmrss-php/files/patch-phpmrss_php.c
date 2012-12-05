--- php.c	2008-01-25 19:32:24.000000000 +0100
+++ php.c 	2012-08-20 03:10:45.000000000 +0200
@@ -58,7 +58,7 @@
 return SUCCESS;
 }
 
-static function_entry mrss_functions[] = {
+static zend_function_entry mrss_functions[] = {
   PHP_FE (mrss_parse_url, NULL) 
   PHP_FE (mrss_parse_url_with_options, NULL) 
   PHP_FE (mrss_parse_file, NULL) 
