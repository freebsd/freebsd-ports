--- Xvnc/lib/font/bitmap/fontink.c.orig	2000-04-12 11:18:29.000000000 -0700
+++ Xvnc/lib/font/bitmap/fontink.c	2013-10-30 23:18:04.000000000 -0700
@@ -94,7 +94,7 @@
     pInk->rightSideBearing = leftBearing;
     pInk->ascent = 0;
     pInk->descent = 0;
-    return;
+    return(0);
 found_ascent:
     pInk->ascent = vpos - descent + 1;
 
@@ -215,5 +215,5 @@
 	    out_line += out_bytes;
 	}
     }
-    return;
+    return(0);
 }
