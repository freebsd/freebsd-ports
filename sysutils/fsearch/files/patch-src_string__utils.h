--- src/string_utils.h.orig	2020-02-24 11:50:22 UTC
+++ src/string_utils.h
@@ -30,3 +30,7 @@ char *
 fs_str_copy (char *dest,
              char *end,
              const char *src);
+
+int
+strverscmp (const char *s1,
+            const char *s2);
