--- src/webserver/src/php_syntree.cpp.orig	2016-09-16 09:55:07.000000000 +0200
+++ src/webserver/src/php_syntree.cpp	2018-03-15 03:38:18.205741000 +0100
@@ -926,7 +926,7 @@
 	switch(val->type) {
 		case PHP_VAL_NONE: buff[0] = 0; break;
 		case PHP_VAL_BOOL:
-		case PHP_VAL_INT: snprintf(buff, sizeof(buff), "%"PRIu64, val->int_val); break;
+		case PHP_VAL_INT: snprintf(buff, sizeof(buff), "%" PRIu64, val->int_val); break;
 		case PHP_VAL_FLOAT: snprintf(buff, sizeof(buff), "%.02f", val->float_val); break;
 		case PHP_VAL_STRING: return;
 		case PHP_VAL_ARRAY: {
