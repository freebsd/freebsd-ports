--- smb_streams.c.orig	2023-04-17 03:27:10 UTC
+++ smb_streams.c
@@ -270,7 +270,7 @@ static int php_smb_ops_stat(php_stream *stream, php_st
 	return 0;
 }
 
-static int php_smb_ops_seek(php_stream *stream, off_t offset, int whence, off_t *newoffset TSRMLS_DC)
+static int php_smb_ops_seek(php_stream *stream, zend_off_t offset, int whence, zend_off_t *newoffset TSRMLS_DC)
 {
 	STREAM_DATA_FROM_STREAM();
 
