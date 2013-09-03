--- draw.c.orig	2008-01-24 16:43:17.000000000 +0100
+++ draw.c	2013-09-03 06:48:44.000000000 +0200
@@ -5471,12 +5471,12 @@
 		    XFT_FAMILY, XftTypeString, font,
 		    XFT_ENCODING, XftTypeString, registry,
 		    XFT_STYLE, XftTypeString, style,
-		    XFT_PIXEL_SIZE, XftTypeDouble, (float)csize, 0);
+		    XFT_PIXEL_SIZE, XftTypeDouble, (float)csize, NULL);
 	} else {
 		xftfont = XftFontOpen(display, screen,
 		    XFT_FAMILY, XftTypeString, font,
 		    XFT_ENCODING, XftTypeString, registry,
-		    XFT_PIXEL_SIZE, XftTypeDouble, (float)csize, 0);
+		    XFT_PIXEL_SIZE, XftTypeDouble, (float)csize, NULL);
 	}
 	if (xftfont == 0) {
 		free(xfont);
