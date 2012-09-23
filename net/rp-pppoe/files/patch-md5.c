--- ./md5.c.orig	2012-08-17 20:31:25.000000000 +0200
+++ ./md5.c	2012-09-23 17:27:55.000000000 +0200
@@ -141,7 +141,7 @@
     MD5Transform(ctx->buf, (uint32 *) ctx->in);
     byteReverse((unsigned char *) ctx->buf, 4);
     memcpy(digest, ctx->buf, 16);
-    memset(ctx, 0, sizeof(ctx));	/* In case it's sensitive */
+    memset(ctx, 0, sizeof(*ctx));	/* In case it's sensitive */
 }
 
 #ifndef ASM_MD5
