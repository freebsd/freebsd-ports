--- StrToPmap.c.org	Fri Apr 11 01:27:17 1997
+++ StrToPmap.c	Fri Apr 11 01:27:38 1997
@@ -90,8 +90,7 @@
 	done(pixmap, Pixmap2);
 	return;
     }
-
-    pixmap[0] = locate_pixmap_file (*((Screen **) args[0].addr), name,
+    pixmap[0] = LocatePixmapFile(*((Screen **) args[0].addr), name,
 			       NULL, 0, NULL, NULL, &pixmap[1]);
 
     if (pixmap[0] != None) {
