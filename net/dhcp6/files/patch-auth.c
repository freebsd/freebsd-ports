--- auth.c.orig	2007-03-21 09:52:57 UTC
+++ auth.c
@@ -222,7 +222,7 @@ hmacmd5_invalidate(hmacmd5_t *ctx)
 {
 	md5_invalidate(&ctx->md5ctx);
 	memset(ctx->key, 0, sizeof(ctx->key));
-	memset(ctx, 0, sizeof(ctx));
+	memset(ctx, 0, sizeof(*ctx));
 }
 
 /*
