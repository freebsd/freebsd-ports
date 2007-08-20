--- pop3.c	Fri Aug 10 04:11:56 2007
+++ pop3.c	Fri Aug 10 04:12:25 2007
@@ -172,8 +172,12 @@
 
 	intern = emalloc(sizeof(pop3_object));
 	intern->zo.ce = class_type;
+#if ZEND_MODULE_API_NO >= 20050922
+	intern->zo.guards = NULL;
+#else
 	intern->zo.in_get = 0;
 	intern->zo.in_set = 0;
+#endif
 	intern->zo.properties = NULL;
 	intern->ptr = NULL;
 
