--- buffer.c.orig	2008-03-31 19:37:15 UTC
+++ buffer.c
@@ -136,46 +136,36 @@ char *buffer_consume_all(buffer B, char *str, size_t *
     return str;
 }
 
-/* buffer_consume_to_mark BUFFER MARK MLEN STR SLEN
- * Consume data from BUFFER up to and including MARK of length MLEN, returning
+/* buffer_consume_to_mark BUFFER MARK STR SLEN
+ * Consume data from BUFFER up to and including single character MARK, returning
  * a pointer to a string allocated with malloc(3) or NULL if the mark was not
  * found. The number of bytes consumed is recorded in SLEN. If STR is not
  * NULL, it must point to a buffer of length at least *SLEN allocated with
  * malloc(3); this buffer will be used as is if the returned string is small
  * enough, or reallocated with realloc(3) otherwise. The returned string is
- * null-terminated.
- *
- * This uses a Boyer-Moore search, but we can't just reuse memstr because we
- * may have to search across the end of the buffer. */
-char *buffer_consume_to_mark(buffer B, const char *mark, const size_t mlen, char *str, size_t *slen) {
-    size_t skip[256], a;
+ * null-terminated. */
+char *buffer_consume_to_mark(buffer B, const char *mark, char *str, size_t *slen) {
+    size_t a;
     int k;
 
     assert(B);
-    assert(mlen > 0 && mlen <= (size_t)INT_MAX);
     
-    if ((a = buffer_available(B)) < mlen) return NULL;
+    if ((a = buffer_available(B)) < 1) return NULL;
 
     assert(a <= (size_t)INT_MAX);
 
-    /* Oh dear. Should special-case the mlen == 1 case, since it's the only
-     * one we use.... */
-    for (k = 0; k < 256; ++k) skip[k] = mlen;
-    for (k = 0; k < (int)mlen - 1; ++k) skip[(unsigned char)mark[k]] = mlen - k - 1;
-
-    for (k = (int)mlen - 1; k < (int)a; k += skip[(unsigned char)mark[k]]) {
-        int i, j;
-        for (j = (int)mlen - 1, i = k; j >= 0 && B->buf[(B->get + i) % B->len] == mark[j]; j--) i--;
-        if (j == -1) {
-            /* Have found the mark at location i + 1. */
-            i += 1 + mlen;  /* account for mark and terminating null */
-            if (!str || *slen < (size_t)i + 1)
-                str = xrealloc(str, (size_t)i + 1);
-            *slen = (size_t)i + 1;
-            for (j = 0; j < i; ++j)
+    for (k = 0; k < (int)a; k++) {
+        if (B->buf[(B->get + k) % B->len] == mark[0]) {
+            int j, len;
+            /* Have found the mark at location k. */
+            len = k + 1; /* string length */
+            if (!str || *slen < (size_t)len + 1)
+                str = xrealloc(str, (size_t)len + 1);
+            *slen = (size_t)len + 1;
+            for (j = 0; j < len; j++)
                 str[j] = B->buf[(B->get + j) % B->len];
             str[j] = 0;
-            B->get = (B->get + i) % B->len;
+            B->get = (B->get + len) % B->len;
             return str;
         }
     }
