diff --git a/plugins/check_http.c b/plugins/check_http.c
--- plugins/check_http.c.old
+++ plugins/check_http.c
@@ -1462,7 +1462,13 @@ char *unchunk_content(const char *content) {
     memcpy(result + (overall_size - size_of_chunk), start_of_chunk, size_of_chunk);
   }

-  result[overall_size] = '\0';
+  if (overall_size == 0 && result == NULL) {
+    // We might just have received the end chunk without previous content, so result is never allocated
+    result = calloc(1, sizeof(char));
+    // No error handling here, we can only return NULL anyway
+  } else {
+    result[overall_size] = '\0';
+  }
   return result;
 }
