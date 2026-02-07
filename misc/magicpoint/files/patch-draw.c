--- draw.c.orig	2008-01-24 15:43:17 UTC
+++ draw.c
@@ -5471,12 +5471,12 @@ xft_setfont(xfontarg, csize, registry)
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
