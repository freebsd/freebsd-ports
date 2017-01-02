--- runtime/stream.c.orig	2016-11-13 15:46:26 UTC
+++ runtime/stream.c
@@ -1153,7 +1153,10 @@ tryTTYRecover(strm_t *pThis, int err)
 #ifndef __FreeBSD__
 	if(err == ERR_TTYHUP) {
 #else
-	if(err == ERR_TTYHUP || err == ENXIO) {
+	/* Try to reopen our file descriptor even on errno 6, FreeBSD bug 200429
+	 * Also try on errno 5, FreeBSD bug 211033
+	 */
+	if(err == ERR_TTYHUP || err == ENXIO || err == EIO) {
 #endif /* __FreeBSD__ */
 		close(pThis->fd);
 		CHKiRet(doPhysOpen(pThis));
