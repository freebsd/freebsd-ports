--- img2xterm.c.orig	2024-01-11 14:08:58 UTC
+++ img2xterm.c
@@ -7,7 +7,7 @@
 #include <sys/ioctl.h>
 #include <limits.h>
 #include <math.h>
-#include <wand/MagickWand.h>
+#include <MagickWand/MagickWand.h>
 #include <unistd.h>
 
 #ifndef NO_CURSES
@@ -288,7 +288,7 @@ void xtermfit(MagickWand* wand)
 	int scaled_width = (int)floor(rs > ri ? wi * hs / hi : ws);
 	int scaled_height = (int)floor(rs > ri ? hs : hi * ws / wi);
 
-	MagickResizeImage(wand, scaled_width, scaled_height, LanczosFilter, 1);
+	MagickResizeImage(wand, scaled_width, scaled_height, LanczosFilter);
 }
 
 void usage(int ret, const char* binname)
