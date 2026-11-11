--- aeron-client/src/main/c/uri/aeron_uri_string_builder.c.orig	2026-11-11 08:03:01 UTC
+++ aeron-client/src/main/c/uri/aeron_uri_string_builder.c
@@ -250,8 +250,9 @@ static void aeron_uri_string_builder_print(void *clien
         return;
     }
 
+    size_t remaining = ctx->buffer_len - ctx->offset;
     int result = snprintf(
-        ctx->buffer + ctx->offset, ctx->buffer_len - ctx->offset, "%s%s=%s", ctx->delimiter, entry->key, entry->value);
+        ctx->buffer + ctx->offset, remaining, "%s%s=%s", ctx->delimiter, entry->key, entry->value);
 
     if (result < 0)
     {
@@ -260,6 +261,12 @@ static void aeron_uri_string_builder_print(void *clien
         return;
     }
 
+    if ((size_t)result >= remaining)
+    {
+        ctx->offset = ctx->buffer_len - 1;
+        return;
+    }
+
     ctx->offset += (size_t)result;
     ctx->delimiter = "|";
 }
@@ -283,13 +290,20 @@ int aeron_uri_string_builder_sprint(aeron_uri_string_b
 
     if (NULL != entry)
     {
-        int result = snprintf(ctx.buffer + ctx.offset, ctx.buffer_len - ctx.offset, "%s:", entry->value);
+        size_t remaining = ctx.buffer_len - ctx.offset;
+        int result = snprintf(ctx.buffer + ctx.offset, remaining, "%s:", entry->value);
         if (result < 0)
         {
             AERON_SET_ERR(result, "Failed to print uri prefix: %s", entry->value);
             return -1;
         }
 
+        if ((size_t)result >= remaining)
+        {
+            ctx.offset = ctx.buffer_len - 1;
+            return 0;
+        }
+
         ctx.offset += (size_t)result;
     }
 
@@ -304,11 +318,18 @@ int aeron_uri_string_builder_sprint(aeron_uri_string_b
         return -1;
     }
 
-    int result = snprintf(ctx.buffer + ctx.offset, ctx.buffer_len - ctx.offset, "aeron:%s", entry->value);
+    size_t remaining = ctx.buffer_len - ctx.offset;
+    int result = snprintf(ctx.buffer + ctx.offset, remaining, "aeron:%s", entry->value);
     if (result < 0)
     {
         AERON_SET_ERR(result, "Failed to print uri media: %s", entry->value);
         return -1;
+    }
+
+    if ((size_t)result >= remaining)
+    {
+        ctx.offset = ctx.buffer_len - 1;
+        return 0;
     }
 
     ctx.offset += (size_t)result;
