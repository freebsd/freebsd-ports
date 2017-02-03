--- src/string_utils.c.orig	2016-10-16 16:07:25 UTC
+++ src/string_utils.c
@@ -17,6 +17,7 @@
    */
 
 #define _GNU_SOURCE
+#include <glib.h>
 #include <stdlib.h>
 #include <ctype.h>
 #include <stdint.h>
@@ -52,9 +53,6 @@ fourbyte_strstr(const unsigned char *h, 
     return *h ? (char *)h-3 : 0;
 }
 
-#define MAX(a,b) ((a)>(b)?(a):(b))
-#define MIN(a,b) ((a)<(b)?(a):(b))
-
 #define BITOP(a,b,op) \
     ((a)[(size_t)(b)/(8*sizeof *(a))] op (size_t)1<<((size_t)(b)%(8*sizeof *(a))))
 
@@ -220,3 +218,20 @@ fsearch_strstr (const char *haystack,
 {
     return my_strstr (haystack, needle);
 }
+
+int
+strverscmp (const char *s1,
+            const char *s2)
+{
+    gchar *tmp1, *tmp2;
+    gint ret;
+
+    tmp1 = g_utf8_collate_key_for_filename(s1, -1);
+    tmp2 = g_utf8_collate_key_for_filename(s2, -1);
+
+    ret = strcmp(tmp1, tmp2);
+
+    g_free(tmp1);
+    g_free(tmp2);
+    return ret;
+}
