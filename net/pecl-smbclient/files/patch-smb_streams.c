Obtained from:	https://github.com/eduardok/libsmbclient-php/commit/a8eab234dd19e32a73740bdd5689e36324b8be5d

--- smb_streams.c.orig	2018-12-24 15:25:25 UTC
+++ smb_streams.c
@@ -190,7 +190,11 @@ static int php_smb_ops_flush(php_stream *stream TSRMLS
 	return 0;
 }
 
+#if PHP_VERSION_ID < 70400
 static size_t php_smb_ops_read(php_stream *stream, char *buf, size_t count TSRMLS_DC)
+#else
+static ssize_t php_smb_ops_read(php_stream *stream, char *buf, size_t count TSRMLS_DC)
+#endif
 {
 	ssize_t n = 0;
 	STREAM_DATA_FROM_STREAM();
@@ -208,12 +212,20 @@ static size_t php_smb_ops_read(php_stream *stream, cha
 	if (n == 0 || n < (ssize_t)count) {
 		stream->eof = 1;
 	}
+#if PHP_VERSION_ID < 70400
 	return (n < 1 ? 0 : (size_t)n);
+#else
+	return n;
+#endif
 }
 
+#if PHP_VERSION_ID < 70400
 static size_t php_smb_ops_write(php_stream *stream, const char *buf, size_t count TSRMLS_DC)
+#else
+static ssize_t php_smb_ops_write(php_stream *stream, const char *buf, size_t count TSRMLS_DC)
+#endif
 {
-	size_t len = 0;
+	ssize_t len = 0;
 	STREAM_DATA_FROM_STREAM();
 
 	if (!self || !self->handle) {
@@ -225,7 +237,12 @@ static size_t php_smb_ops_write(php_stream *stream, co
 	if (self->smbc_write) {
 		len = self->smbc_write(self->state->ctx, self->handle, buf, count);
 	}
+
+#if PHP_VERSION_ID < 70400
+	return (len < 0 ? 0 : (size_t)len);
+#else
 	return len;
+#endif
 }
 
 static int php_smb_ops_stat(php_stream *stream, php_stream_statbuf *ssb TSRMLS_DC) /* {{{ */
@@ -500,7 +517,11 @@ static int php_smbdir_ops_close(php_stream *stream, in
 	return EOF;
 }
 
+#if PHP_VERSION_ID < 70400
 static size_t php_smbdir_ops_read(php_stream *stream, char *buf, size_t count TSRMLS_DC)
+#else
+static ssize_t php_smbdir_ops_read(php_stream *stream, char *buf, size_t count TSRMLS_DC)
+#endif
 {
 	struct smbc_dirent *dirent;
 	php_stream_dirent *ent = (php_stream_dirent*)buf;
