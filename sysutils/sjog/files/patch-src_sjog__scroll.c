
$FreeBSD$

--- src/sjog_scroll.c.orig	Sun Aug 22 17:08:03 2004
+++ src/sjog_scroll.c	Sun Aug 22 17:08:13 2004
@@ -65,7 +65,7 @@
         sjog_scroll_up();
         break;
 
-     default:
+     default: break;
 
    }
 
