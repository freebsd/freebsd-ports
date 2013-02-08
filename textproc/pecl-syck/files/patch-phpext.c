--- phpext.c.orig	2012-12-05 11:19:34.767180000 +0800
+++ phpext.c	2012-12-05 11:20:01.379824000 +0800
@@ -198,7 +198,7 @@
 
 
 
-function_entry syck_functions[] = {
+zend_function_entry syck_functions[] = {
 	PHP_FE(syck_load, arginfo_syck_load)
 	PHP_FE(syck_dump, arginfo_syck_dump)
 	{NULL, NULL, NULL}	/* Must be the last line in syck_functions[] */
@@ -403,7 +403,7 @@
 
 				strncpy(classname, n->type_id + 12, classname_len + 1);
 
-				if (FAILURE == zend_lookup_class_ex(classname, classname_len, 1, &ce TSRMLS_CC)) {
+				if (FAILURE == zend_lookup_class(classname, classname_len, &ce TSRMLS_CC)) {
 					zend_throw_exception_ex(syck_exception_entry, 0 TSRMLS_CC, "Couldn't find %s class on line %d, col %d: '%s'", classname, p->linect + 1, p->cursor - p->lineptr, p->lineptr);
 					efree(classname);
 					break;
@@ -439,7 +439,7 @@
 
 				strncpy(classname, n->type_id + 11, classname_len + 1);
 
-				if (FAILURE == zend_lookup_class_ex(classname, classname_len, 1, &ce TSRMLS_CC)) {
+				if (FAILURE == zend_lookup_class(classname, classname_len, &ce TSRMLS_CC)) {
 					zend_throw_exception_ex(syck_exception_entry, 0 TSRMLS_CC, "Couldn't find %s class on line %d, col %d: '%s'", classname, p->linect + 1, p->cursor - p->lineptr, p->lineptr);
 					efree(classname);
 					break;
@@ -511,7 +511,7 @@
 
 				strncpy(classname, n->type_id + 10, classname_len + 1);
 
-				if (FAILURE == zend_lookup_class_ex(classname, classname_len, 1, &ce TSRMLS_CC)) {
+				if (FAILURE == zend_lookup_class(classname, classname_len, &ce TSRMLS_CC)) {
 					zend_throw_exception_ex(syck_exception_entry, 0 TSRMLS_CC, "Couldn't find %s class on line %d, col %d: '%s'", classname, p->linect + 1, p->cursor - p->lineptr, p->lineptr);
 					efree(classname);
 					break;
