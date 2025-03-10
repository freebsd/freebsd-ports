--- src/plugins/fd/bpipe-fd.c.orig	2024-03-22 09:48:41 UTC
+++ src/plugins/fd/bpipe-fd.c
@@ -202,7 +202,9 @@ static bRC freePlugin(bpContext *ctx)
    if (!p_ctx) {
       return bRC_Error;
    }
-   bfree_and_null(p_ctx->cmd);
+   if (p_ctx->cmd) {
+      free(p_ctx->cmd);                  /* free any allocated command string */
+   }
    free_and_null_pool_memory(p_ctx->restore_obj_buf);
    if (p_ctx->rop_writer) {
       restoreobj *rop;
