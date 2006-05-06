--- soap.c.orig	Fri Mar 24 09:45:54 2006
+++ soap.c	Sat May  6 10:28:32 2006
@@ -23,7 +23,7 @@
 #include "config.h"
 #endif
 #include "php_soap.h"
-#if HAVE_PHP_SESSION && !defined(COMPILE_DL_SESSION)
+#if HAVE_PHP_SESSION
 #include "ext/session/php_session.h"
 #endif
 #ifdef ZEND_ENGINE_2
@@ -1523,7 +1523,7 @@
 
 	soap_obj = NULL;
 	if (service->type == SOAP_CLASS) {
-#if HAVE_PHP_SESSION && !defined(COMPILE_DL_SESSION)
+#if HAVE_PHP_SESSION
 		/* If persistent then set soap_obj from from the previous created session (if available) */
 		if (service->soap_class.persistance == SOAP_PERSISTENCE_SESSION) {
 			zval **tmp_soap;
@@ -1610,7 +1610,7 @@
 				}
 				efree(class_name);
 			}
-#if HAVE_PHP_SESSION && !defined(COMPILE_DL_SESSION)
+#if HAVE_PHP_SESSION
 			/* If session then update session hash with new object */
 			if (service->soap_class.persistance == SOAP_PERSISTENCE_SESSION) {
 				zval **tmp_soap_pp;
@@ -1706,7 +1706,7 @@
 	     zend_hash_exists(function_table, ZEND_CALL_FUNC_NAME, sizeof(ZEND_CALL_FUNC_NAME)))) {
 		if (service->type == SOAP_CLASS) {
 			call_status = call_user_function(NULL, &soap_obj, &function_name, &retval, num_params, params TSRMLS_CC);
-#if HAVE_PHP_SESSION && !defined(COMPILE_DL_SESSION)
+#if HAVE_PHP_SESSION
 			if (service->soap_class.persistance != SOAP_PERSISTENCE_SESSION) {
 				zval_ptr_dtor(&soap_obj);
 			}
@@ -1728,7 +1728,7 @@
 		    instanceof_function(Z_OBJCE_P(EG(exception)), soap_fault_class_entry TSRMLS_CC)) {
 			soap_server_fault_ex(function, EG(exception), NULL TSRMLS_CC);
 		}
-#if HAVE_PHP_SESSION && !defined(COMPILE_DL_SESSION)
+#if HAVE_PHP_SESSION
 		if (soap_obj && service->soap_class.persistance != SOAP_PERSISTENCE_SESSION) {
 #else
 		if (soap_obj) {
