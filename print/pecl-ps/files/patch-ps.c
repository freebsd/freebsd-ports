--- ps.c	2006-05-31 23:09:47.000000000 +1000
+++ ps.c	2008-09-22 13:50:07.000000000 +1000
@@ -1285,7 +1285,8 @@
 	zval *zps;
 	char *type, *filename, *image, *stringparam = NULL;
 	int type_len, filename_len, stringparam_len;
-	int imageid, intparam = 0;
+	long imageid;
+	int intparam = 0;
 	PSDoc *ps;
 
 	if (FAILURE == zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "rss|sl", &zps, &type, &type_len, &filename, &filename_len, &stringparam, &stringparam_len, &intparam)) {
@@ -1316,7 +1317,7 @@
 {
 	zval **arg1, **arg2;
 	int i, j, color, count;
-	int imageid;
+	long imageid;
 	gdImagePtr im;
 	unsigned char *buffer, *ptr;
 	PSDoc *ps;
@@ -1382,7 +1383,7 @@
 PHP_FUNCTION(ps_close_image)
 {
 	zval *zps;
-	int imageid;
+	long imageid;
 	PSDoc *ps;
 
 	if (FAILURE == zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "rl", &zps, &imageid)) {
@@ -1400,7 +1401,7 @@
 PHP_FUNCTION(ps_place_image)
 {
 	zval *zps;
-	int imageid;
+	long imageid;
 	double x, y, scale;
 	PSDoc *ps;
 
@@ -1761,7 +1762,7 @@
 	zval **arg1, **arg2, **arg3, **arg4, **arg5, **arg6, **arg7;
 	PSDoc *ps;
 	char *image;
-	int imageid;
+	long imageid;
 
 	if (ZEND_NUM_ARGS() != 7 || zend_get_parameters_ex(7, &arg1, &arg2, &arg3, &arg4, &arg5, &arg6, &arg7) == FAILURE) {
 		WRONG_PARAM_COUNT;
@@ -1802,7 +1803,7 @@
 	char *type, *params, *source, *data;
 	int type_len, params_len, source_len, data_len;
 	int length, width, height, components, bpc;
-	int imageid;
+	long imageid;
 	char *image;
 	PSDoc *ps;
 
@@ -2024,7 +2025,7 @@
  * Add an existing image as thumbnail for the current page. */
 PHP_FUNCTION(ps_add_thumbnail) {
 	zval *zps;
-	int imageid;
+	long imageid;
 	PSDoc *ps;
 
 	if (FAILURE == zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "rl", &zps, &imageid)) {
