--- src/webserver/src/php_core_lib.cpp.orig	2016-09-16 09:55:07.000000000 +0200
+++ src/webserver/src/php_core_lib.cpp	2018-03-17 09:46:29.766922000 +0100
@@ -71,7 +71,7 @@
 	if ( ref ) printf("&");
 	switch(node->type) {
 		case PHP_VAL_BOOL: printf("bool(%s)\n", node->int_val ? "true" : "false"); break;
-		case PHP_VAL_INT: printf("int(%"PRIu64")\n", node->int_val); break;
+		case PHP_VAL_INT: printf("int(%" PRIu64 ")\n", node->int_val); break;
 		case PHP_VAL_FLOAT: printf("float(%f)\n", node->float_val); break;
 		case PHP_VAL_STRING: printf("string(%d) \"%s\"\n", (int)strlen(node->str_val), node->str_val); break;
 		case PHP_VAL_OBJECT: printf("Object(%s)\n", node->obj_val.class_name); break;
