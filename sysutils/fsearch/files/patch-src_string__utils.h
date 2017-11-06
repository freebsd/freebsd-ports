--- src/string_utils.h.orig	2016-10-16 16:07:25 UTC
+++ src/string_utils.h
@@ -28,3 +28,7 @@ const char *
 fsearch_strcasestr (const char *haystack,
                     const char *needle,
                     size_t needle_len);
+
+int
+strverscmp (const char *s1,
+            const char *s2);
