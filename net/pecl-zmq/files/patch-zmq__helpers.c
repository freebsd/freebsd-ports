--- zmq_helpers.c.orig	2016-02-01 01:50:43 UTC
+++ zmq_helpers.c
@@ -63,7 +63,7 @@ char *php_zmq_printable_func (zend_fcall_info *fci, ze
 	char *buffer = NULL;
 
 	if (fci->object) {
-		spprintf (&buffer, 0, "%s::%s", fci->object->ce->name->val, fci_cache->function_handler->common.function_name);
+		spprintf (&buffer, 0, "%s::%s", fci->object->ce->name->val, ZSTR_VAL(fci_cache->function_handler->common.function_name));
 	} else {
 		if (Z_TYPE (fci->function_name) == IS_OBJECT) {
 			spprintf (&buffer, 0, "%s", Z_OBJCE (fci->function_name)->name->val);
@@ -74,4 +74,4 @@ char *php_zmq_printable_func (zend_fcall_info *fci, ze
 	}
 	return buffer;
 }
-/* }}} */
\ No newline at end of file
+/* }}} */
