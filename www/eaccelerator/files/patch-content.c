--- content.c.orig	Sun Jul 10 10:12:33 2005
+++ content.c	Thu Feb  2 09:40:00 2006
@@ -593,10 +593,13 @@ PHP_FUNCTION(eaccelerator_cache_result) 
     if (zend_eval_string(code, return_value, eval_name TSRMLS_CC) == SUCCESS &&
         eaccelerator_content_cache_place != eaccelerator_none) {
 
+#ifndef ZEND_ENGINE_2_1
+/* No worko on php >= 5.1.0 */
       /* clean garbage */
       while (EG(garbage_ptr)) {
         zval_ptr_dtor(&EG(garbage)[--EG(garbage_ptr)]);
       }
+#endif
 
       eaccelerator_put(key, key_len, return_value, ttl, eaccelerator_content_cache_place TSRMLS_CC);
     }
