--- lib/zlog.c.orig	2020-06-30 11:08:57 UTC
+++ lib/zlog.c
@@ -246,10 +246,10 @@ void zlog_tls_buffer_init(void)
 	fchown(mmfd, zlog_uid, zlog_gid);
 
 #ifdef HAVE_POSIX_FALLOCATE
-	if (posix_fallocate(mmfd, 0, TLS_LOG_BUF_SIZE) < 0) {
-#else
-	if (ftruncate(mmfd, TLS_LOG_BUF_SIZE) < 0) {
+	if (posix_fallocate(mmfd, 0, TLS_LOG_BUF_SIZE) != 0)
+	/* note next statement is under above if() */
 #endif
+	if (ftruncate(mmfd, TLS_LOG_BUF_SIZE) < 0) {
 		zlog_err("failed to allocate thread log buffer \"%s\": %s",
 			 mmpath, strerror(errno));
 		goto out_anon_unlink;
