--- src/kanji_conv.c.orig	Wed Jan  3 16:14:39 2001
+++ src/kanji_conv.c	Thu Apr 19 15:51:21 2001
@@ -32,3 +32,3 @@
 #ifdef HAVE_ICONV
-#include <iconv.h>
+#include <giconv.h>
 #endif
