--- main.c.orig	Wed Nov  3 19:43:23 2004
+++ main.c	Mon Apr  4 10:05:06 2005
@@ -16,11 +16,11 @@
 #include <gtk/gtk.h>
 #include "gfx/mask.xpm"
 
-#define GFX_GO "gfx/go.png"
-#define GFX_GO_ "gfx/go_.png"
-#define GFX_NOTDETECTED "gfx/notdetected.png"
-#define GFX_CAPPED "gfx/capped.png"
-#define GFX_UNCAPPED "gfx/uncapped.png"
+#define GFX_GO "%%PREFIX%%/share/gopod/go.png"
+#define GFX_GO_ "%%PREFIX%%/share/gopod/go_.png"
+#define GFX_NOTDETECTED "%%PREFIX%%/share/gopod/notdetected.png"
+#define GFX_CAPPED "%%PREFIX%%/share/gopod/capped.png"
+#define GFX_UNCAPPED "%%PREFIX%%/share/gopod/uncapped.png"
 
 #if defined(__LINUX__)
 #define DEV "/dev/sd%c"
@@ -69,10 +69,10 @@
 {
     char x;
     
-    for (x = START; x <= END; x++)
+    for (x = 0; x <= 15; x++)
     {
         char devstring[8];
-        sprintf(devstring, DEV, x);
+        sprintf(devstring, "/dev/da%i", x);
         dev = open(devstring, O_RDWR);
         lseek(dev, FIRMWARE_START, SEEK_CUR); 
         read(dev, buffer, BLOCK_SIZE);
