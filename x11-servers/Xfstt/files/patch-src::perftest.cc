--- src/perftest.cc.orig	Thu Nov 14 21:08:09 2002
+++ src/perftest.cc	Wed Nov 20 23:17:01 2002
@@ -21,7 +21,7 @@
  *
  */
 
-#define TTFONTDIR	"/usr/share/fonts/truetype"
+#define TTFONTDIR	"%%TTFONTDIR%%"
 #define MAXFONTBUFSIZE (2048*2048)
 
 #include "ttf.h"
