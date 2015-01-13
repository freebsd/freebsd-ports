--- src/cadaver.c.orig	2010-10-15 17:01:46.000000000 +0200
+++ src/cadaver.c	2010-10-15 17:02:29.000000000 +0200
@@ -42,6 +42,9 @@
 #ifdef HAVE_LOCALE_H
 #include <locale.h>
 #endif
+#ifdef HAVE_SETLOCALE
+#include <locale.h>
+#endif
 
 
 #include <errno.h>
