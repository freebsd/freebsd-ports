--- src/vasprintf.c.orig	2014-09-09 13:16:32.729289288 +0000
+++ src/vasprintf.c	2014-09-09 13:16:52.201287983 +0000
@@ -42,6 +42,7 @@
 #endif /* HAVE_VA_COPY */
 
 #ifdef HAVE_WCHAR_H
+#include <stddef.h>
 #include <wchar.h>
 #endif
 
