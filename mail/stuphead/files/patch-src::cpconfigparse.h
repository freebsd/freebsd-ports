--- src/cpconfigparse.h.orig	Mon May 20 13:11:39 2002
+++ src/cpconfigparse.h	Mon May 20 13:12:00 2002
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
