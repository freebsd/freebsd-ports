--- execute.c.orig	2011-06-21 12:07:15.000000000 +0200
+++ execute.c	2011-06-21 12:08:30.000000000 +0200
@@ -1087,7 +1087,7 @@
 	zend_str_tolower(lcname, func_name_len);
 #else
 	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &lcname, &func_name_len) == FAILURE) {
-		return;
+		return 0;
 	}
 
 	/* Ignore leading "\" */
@@ -1501,7 +1501,7 @@
 {
 #ifdef PHP_ATLEAST_5_3
 	if (zend_parse_parameters_none() == FAILURE) {
-		return;
+		return 0;
 	}
 #else
         int argc = ZEND_NUM_ARGS();
