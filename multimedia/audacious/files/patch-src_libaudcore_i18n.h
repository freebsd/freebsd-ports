--- src/libaudcore/i18n.h.orig	2024-06-12 20:16:04 UTC
+++ src/libaudcore/i18n.h
@@ -36,8 +36,9 @@
 
 #else
 
-#define _(String) (String)
+#define _(String) ((char *)String)
 #define N_(String) (String)
+#define gettext(str) (str)
 #define dgettext(package, str) (str)
 #define dngettext(package, str1, str2, count) (count > 1 ? str2 : str1)
 #define ngettext(str1, str2, count) (count > 1 ? str2 : str1)
