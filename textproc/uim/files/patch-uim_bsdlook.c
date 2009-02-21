--- ./uim/bsdlook.c.orig	2009-01-06 15:42:58.000000000 +0900
+++ ./uim/bsdlook.c	2009-01-23 03:01:10.000000000 +0900
@@ -166,7 +166,7 @@
 	if (!ctx)
 		return;
 
-	if (ctx->front0 > 0 && munmap(ctx->front0, ctx->len) == -1)
+	if (!ctx->front0 && munmap(ctx->front0, ctx->len) == -1)
 		perror("uim_look_finish");
 
 	if (ctx->fd > 0)
