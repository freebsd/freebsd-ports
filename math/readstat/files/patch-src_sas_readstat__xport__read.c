--- src/sas/readstat_xport_read.c.orig	2023-05-02 13:35:52 UTC
+++ src/sas/readstat_xport_read.c
@@ -45,7 +45,7 @@ static readstat_error_t xport_update_progress(xport_ct
     return io->update(ctx->file_size, ctx->handle.progress, ctx->user_ctx, io->io_ctx);
 }
 
-static xport_ctx_t *xport_ctx_init() {
+static xport_ctx_t *xport_ctx_init(void) {
     xport_ctx_t *ctx = calloc(1, sizeof(xport_ctx_t));
     return ctx;
 }
