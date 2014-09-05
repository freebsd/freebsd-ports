--- soap.c.orig	2012-03-02 15:46:04.000000000 +0100
+++ soap.c	2012-03-02 15:45:38.000000000 +0100
@@ -23,7 +23,7 @@
 #include "config.h"
 #endif
 #include "php_soap.h"
-#if HAVE_PHP_SESSION && !defined(COMPILE_DL_SESSION)
+#if HAVE_PHP_SESSION
 #include "ext/session/php_session.h"
 #endif
 #include "zend_exceptions.h"
@@ -1639,7 +1639,7 @@
 		soap_obj = service->soap_object;
 		function_table = &((Z_OBJCE_P(soap_obj))->function_table);
 	} else if (service->type == SOAP_CLASS) {
-#if HAVE_PHP_SESSION && !defined(COMPILE_DL_SESSION)
+#if HAVE_PHP_SESSION
 		/* If persistent then set soap_obj from from the previous created session (if available) */
 		if (service->soap_class.persistance == SOAP_PERSISTENCE_SESSION) {
 			zval **tmp_soap;
@@ -1722,7 +1722,7 @@
 				}
 				efree(class_name);
 			}
-#if HAVE_PHP_SESSION && !defined(COMPILE_DL_SESSION)
+#if HAVE_PHP_SESSION
 			/* If session then update session hash with new object */
 			if (service->soap_class.persistance == SOAP_PERSISTENCE_SESSION) {
 				zval **tmp_soap_pp;
@@ -1820,7 +1820,7 @@
 		if (service->type == SOAP_CLASS || service->type == SOAP_OBJECT) {
 			call_status = call_user_function(NULL, &soap_obj, &function_name, retval, num_params, params TSRMLS_CC);
 			if (service->type == SOAP_CLASS) {
-#if HAVE_PHP_SESSION && !defined(COMPILE_DL_SESSION)
+#if HAVE_PHP_SESSION
 				if (service->soap_class.persistance != SOAP_PERSISTENCE_SESSION) {
 					zval_ptr_dtor(&soap_obj);
 					soap_obj = NULL;
@@ -1845,7 +1845,7 @@
 			soap_server_fault_ex(function, EG(exception), NULL TSRMLS_CC);
 		}
 		if (service->type == SOAP_CLASS) {
-#if HAVE_PHP_SESSION && !defined(COMPILE_DL_SESSION)
+#if HAVE_PHP_SESSION
 			if (soap_obj && service->soap_class.persistance != SOAP_PERSISTENCE_SESSION) {
 #else
 			if (soap_obj) {
@@ -1887,7 +1887,7 @@
 			soap_server_fault_ex(function, EG(exception), NULL TSRMLS_CC);
 		}
 		if (service->type == SOAP_CLASS) {
-#if HAVE_PHP_SESSION && !defined(COMPILE_DL_SESSION)
+#if HAVE_PHP_SESSION
 			if (soap_obj && service->soap_class.persistance != SOAP_PERSISTENCE_SESSION) {
 #else
 			if (soap_obj) {
