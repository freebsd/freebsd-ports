
$FreeBSD$

--- src/sjog_brightness.c.orig	Sun Aug 22 17:07:24 2004
+++ src/sjog_brightness.c	Sun Aug 22 17:07:35 2004
@@ -54,7 +54,7 @@
         sjog_set_brightness(currentBrightness);
         break;
 
-     default:
+     default: break;
 
    }
 
