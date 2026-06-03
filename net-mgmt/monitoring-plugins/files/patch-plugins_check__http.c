--- plugins/check_http.c.orig	2025-11-08 16:43:35.500239000 +0100
+++ plugins/check_http.c	2025-11-08 17:09:19.591784000 +0100
@@ -1476,7 +1476,13 @@ char *unchunk_content(const char *content) {
     result = calloc(1, sizeof(char));
     // No error handling here, we can only return NULL anyway
   } else {
-    result[overall_size] = '\0';
+   if (overall_size == 0 && result == NULL) {
+    // We might just have received the end chunk without previous content, so result is never allocated
+    result = calloc(1, sizeof(char));
+    // No error handling here, we can only return NULL anyway
+  } else {
+    result[overall_size] = '\0';	
+      }  
   }
   return result;
 }
