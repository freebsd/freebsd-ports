--- src/kanji_conv.c.orig	Mon Dec 24 12:51:08 2001
+++ src/kanji_conv.c	Mon Dec 24 12:51:21 2001
@@ -30,7 +30,7 @@
 #include <locale.h>
 
 #ifdef HAVE_ICONV
-#include <iconv.h>
+#include <giconv.h>
 #endif
 
 #include "kanji_conv.h"
