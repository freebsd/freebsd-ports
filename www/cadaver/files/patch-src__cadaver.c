--- src/cadaver.c.orig	2022-10-30 10:46:52 UTC
+++ src/cadaver.c
@@ -42,6 +42,9 @@
 #ifdef HAVE_LOCALE_H
 #include <locale.h>
 #endif
+#ifdef HAVE_SETLOCALE
+#include <locale.h>
+#endif
 
 
 #include <errno.h>
