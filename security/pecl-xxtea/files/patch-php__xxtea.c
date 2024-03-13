--- php_xxtea.c.orig	2024-03-12 22:05:18 UTC
+++ php_xxtea.c
@@ -275,7 +275,7 @@ ZEND_FUNCTION(xxtea_encrypt) {
     size_t i, ret_length;
     uint8_t fixed_key[16];
 
-    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ss", &data, &data_len, &key, &key_len) == FAILURE) {
+    if (zend_parse_parameters(ZEND_NUM_ARGS(), "ss", &data, &data_len, &key, &key_len) == FAILURE) {
         return;
     }
     if (data_len == 0) {
@@ -308,7 +308,7 @@ ZEND_FUNCTION(xxtea_decrypt) {
     size_t i, ret_length;
     uint8_t fixed_key[16];
 
-    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ss", &data, &data_len, &key, &key_len) == FAILURE) {
+    if (zend_parse_parameters(ZEND_NUM_ARGS(), "ss", &data, &data_len, &key, &key_len) == FAILURE) {
         return;
     }
     if (data_len == 0) {
@@ -340,7 +340,7 @@ ZEND_MINIT_FUNCTION(xxtea) {
 ZEND_MINIT_FUNCTION(xxtea) {
     zend_class_entry ce;
     INIT_CLASS_ENTRY(ce, "XXTEA", xxtea_method);
-    xxtea_ce = zend_register_internal_class(&ce TSRMLS_CC);
+    xxtea_ce = zend_register_internal_class(&ce);
     return SUCCESS;
 }
 
