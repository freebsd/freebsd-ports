--- src/xfstt.cc.orig	Thu Nov 14 21:08:08 2002
+++ src/xfstt.cc	Wed Nov 20 23:22:03 2002
@@ -31,8 +31,8 @@
 #define UNSTRAPLIMIT	10500U
 
 // Change these if you don't like being FHS complient
-#define TTFONTDIR	"/usr/share/fonts/truetype"
-#define TTCACHEDIR	"/var/cache/xfstt"
+#define TTFONTDIR	"%%TTFONTDIR%%"
+#define TTCACHEDIR	"%%TTFONTDIR%%"
 
 #define TTINFO_LEAF	"ttinfo.dir"
 #define TTNAME_LEAF	"ttname.dir"
