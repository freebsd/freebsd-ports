--- src/conv_iconv.h.orig	Mon May 20 13:08:26 2002
+++ src/conv_iconv.h	Mon May 20 13:09:01 2002
@@ -9,11 +9,7 @@
 #endif
 
 #include <glib.h>
-#ifdef LIBICONV_PLUG
-#include <giconv.h>
-#else
 #include <iconv.h>
-#endif
 #include <gtk/gtk.h>
 
 #define MAX_CHAR_LEN 4
