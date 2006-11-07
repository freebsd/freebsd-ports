--- fileinfo.c.orig	2005/12/20 19:17:00
+++ fileinfo.c	2006/10/10 09:52:06
@@ -121,10 +121,17 @@
 /* {{{ finfo_class_functions
  */
 function_entry finfo_class_functions[] = {
-	ZEND_ME_MAPPING(finfo,		finfo_open,	NULL)
-	ZEND_ME_MAPPING(set_flags,	finfo_set_flags,NULL)
-	ZEND_ME_MAPPING(file,		finfo_file,	NULL)
-	ZEND_ME_MAPPING(buffer,		finfo_buffer,	NULL)
+#if PHP_VERSION_ID >= 50200
+	ZEND_ME_MAPPING(finfo,          finfo_open,     NULL, ZEND_ACC_PUBLIC)
+	ZEND_ME_MAPPING(set_flags,      finfo_set_flags,NULL, ZEND_ACC_PUBLIC)
+	ZEND_ME_MAPPING(file,           finfo_file,     NULL, ZEND_ACC_PUBLIC)
+	ZEND_ME_MAPPING(buffer,         finfo_buffer,   NULL, ZEND_ACC_PUBLIC)
+#else
+	ZEND_ME_MAPPING(finfo,          finfo_open,     NULL)
+	ZEND_ME_MAPPING(set_flags,      finfo_set_flags,NULL)
+	ZEND_ME_MAPPING(file,           finfo_file,     NULL)
+	ZEND_ME_MAPPING(buffer,         finfo_buffer,   NULL)
+#endif
 	{NULL, NULL, NULL}
 };
 /* }}} */
