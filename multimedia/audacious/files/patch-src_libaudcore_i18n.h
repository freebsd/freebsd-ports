--- src/libaudcore/i18n.h.orig	2022-07-10 01:11:00 UTC
+++ src/libaudcore/i18n.h
@@ -34,8 +34,9 @@
 
 #else
 
-#define _(String) (String)
+#define _(String) ((char *)String)
 #define N_(String) (String)
+#define gettext(str) (str)
 #define dgettext(package, str) (str)
 #define dngettext(package, str1, str2, count) (count > 1 ? str2 : str1)
 #define ngettext(str1, str2, count) (count > 1 ? str2 : str1)
