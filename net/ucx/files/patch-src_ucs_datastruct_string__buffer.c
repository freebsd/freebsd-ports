--- src/ucs/datastruct/string_buffer.c.orig	2026-05-17 17:31:16 UTC
+++ src/ucs/datastruct/string_buffer.c
@@ -141,8 +141,13 @@ void ucs_string_buffer_append_iovec(ucs_string_buffer_
     size_t iov_index;
 
     for (iov_index = 0; iov_index < iovcnt; ++iov_index) {
-        ucs_string_buffer_appendf(strb, "%p,%zu|", iov[iov_index].iov_base,
-                                  iov[iov_index].iov_len);
+        if (iov[iov_index].iov_base == NULL) {
+            ucs_string_buffer_appendf(strb, "(nil),%zu|",
+                                      iov[iov_index].iov_len);
+        } else {
+            ucs_string_buffer_appendf(strb, "%p,%zu|", iov[iov_index].iov_base,
+                                      iov[iov_index].iov_len);
+        }
     }
     ucs_string_buffer_rtrim(strb, "|");
 }
