--- ext/standard/file.c.orig	Thu Feb 28 09:26:44 2002
+++ ext/standard/file.c	Tue May  7 13:57:19 2002
@@ -1453,7 +1453,7 @@
 PHP_FUNCTION(mkdir)
 {
 	int dir_len, ret;
-	mode_t mode = 0777;
+	long mode = 0777;
 	char *dir;
 
 	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s|l", &dir, &dir_len, &mode) == FAILURE) {
@@ -1468,7 +1468,7 @@
 		RETURN_FALSE;
 	}
 
-	ret = VCWD_MKDIR(dir, mode);
+	ret = VCWD_MKDIR(dir, (mode_t)mode);
 	if (ret < 0) {
 		php_error(E_WARNING, "mkdir() failed (%s)", strerror(errno));
 		RETURN_FALSE;
