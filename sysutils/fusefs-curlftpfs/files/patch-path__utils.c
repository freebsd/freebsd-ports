--- path_utils.c.orig	2007-11-20 19:27:58 UTC
+++ path_utils.c
@@ -92,3 +92,72 @@ char* get_dir_path(const char* path) {
 
   return ret;
 }
+
+/*
+ * the chars not needed to be escaped:
+ *    unreserved  = ALPHA / DIGIT / "-" / "." / "_" / "~"
+ */
+static inline int is_unreserved_rfc3986(char c)
+{
+    int is_locase_alpha = (c >= 'a' && c <= 'z');
+    int is_upcase_alpha = (c >= 'a' && c <= 'z');
+    int is_digit        = (c >= '0' && c <= '9');
+    int is_special      = c == '-'
+                       || c == '.'
+                       || c == '_'
+                       || c == '~';
+    int is_unreserved = is_locase_alpha
+                      || is_upcase_alpha
+                      || is_digit
+                      || is_special;
+
+    return is_unreserved;
+}
+
+static inline int is_unreserved(char c)
+{
+    return is_unreserved_rfc3986(c) || c == '/';
+}
+
+char* path_to_uri(const char* path)
+{
+    static const char hex[] = "0123456789ABCDEF";
+    size_t path_len = strlen(path);
+    size_t host_len = strlen(ftpfs.host);
+    /* at worst: c -> %XX */
+    char * encoded_path = malloc (3 * path_len + 1);
+    const char * s = path;
+    char * d       = encoded_path;
+
+    /*
+     * 'path' is always prefixed with 'ftpfs.host'
+     */
+    memcpy (d, ftpfs.host, host_len);
+    s += host_len;
+    d += host_len;
+
+    for (; *s; ++s)
+    {
+        char c = *s;
+        if (is_unreserved (c))
+        {
+            *d++ = c;
+        }
+        else
+        {
+            unsigned int hi = ((unsigned)c >> 4) & 0xF;
+            unsigned int lo = ((unsigned)c >> 0) & 0xF;
+            *d++ = '%';
+            *d++ = hex[hi];
+            *d++ = hex[lo];
+        }
+    }
+    *d = '\0';
+
+    return encoded_path;
+}
+
+void free_uri(char* path)
+{
+    free(path);
+}
