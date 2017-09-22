--- libclamav/bytecode_api.c.orig	2016-04-22 15:02:19 UTC
+++ libclamav/bytecode_api.c
@@ -811,8 +811,19 @@ int32_t cli_bcapi_inflate_init(struct cli_bc_ctx *ctx,
         cli_dbgmsg("bytecode api: inflate_init: invalid buffers!\n");
         return -1;
     }
-    memset(&stream, 0, sizeof(stream));
-    ret = inflateInit2(&stream, windowBits);
+    b = cli_realloc(ctx->inflates, sizeof(*ctx->inflates)*n);
+    if (!b) {
+        return -1;
+    }
+    ctx->inflates = b;
+    ctx->ninflates = n;
+    b = &b[n-1];
+
+    b->from = from;
+    b->to = to;
+    b->needSync = 0;
+    memset(&b->stream, 0, sizeof(stream));
+    ret = inflateInit2(&b->stream, windowBits);
     switch (ret) {
         case Z_MEM_ERROR:
             cli_dbgmsg("bytecode api: inflateInit2: out of memory!\n");
@@ -830,19 +841,6 @@ int32_t cli_bcapi_inflate_init(struct cli_bc_ctx *ctx,
             return -1;
     }
 
-    b = cli_realloc(ctx->inflates, sizeof(*ctx->inflates)*n);
-    if (!b) {
-        inflateEnd(&stream);
-        return -1;
-    }
-    ctx->inflates = b;
-    ctx->ninflates = n;
-    b = &b[n-1];
-
-    b->from = from;
-    b->to = to;
-    b->needSync = 0;
-    memcpy(&b->stream, &stream, sizeof(stream));
     return n-1;
 }
 
