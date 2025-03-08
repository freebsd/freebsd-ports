--- src/responder/common/responder_common.c.orig	2026-01-14 15:01:42 UTC
+++ src/responder/common/responder_common.c
@@ -108,7 +108,7 @@ static errno_t get_client_cred(struct cli_ctx *cctx)
     char cmd_line[255] = { 0 };
     int proc_fd;
 
-    ret = getsockopt(cctx->cfd, SOL_SOCKET, SSS_PEERCRED_SOCKET_OPTION, &cctx->creds->ucred,
+    ret = getsockopt(cctx->cfd, SOL_LOCAL, SSS_PEERCRED_SOCKET_OPTION, &cctx->creds->ucred,
                      &client_cred_len);
     if (ret != EOK) {
         talloc_zfree(cctx->creds);
