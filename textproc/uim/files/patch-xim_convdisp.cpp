--- ./xim/convdisp.cpp.orig	2009-01-21 11:16:35.000000000 +0900
+++ ./xim/convdisp.cpp	2009-01-23 02:41:58.000000000 +0900
@@ -87,14 +87,14 @@
     gXftFont = XftFontOpen(XimServer::gDpy, DefaultScreen(XimServer::gDpy),
 		    XFT_FAMILY, XftTypeString, fontname,
 		    XFT_PIXEL_SIZE, XftTypeDouble, (double)DEFAULT_FONT_SIZE,
-		    NULL);
+		    (char *)NULL);
     gXftFontLocale = strdup(setlocale(LC_CTYPE, NULL));
     // maybe not needed, but in case it return NULL...
     if (!gXftFont) {
 	gXftFont = XftFontOpen(XimServer::gDpy, DefaultScreen(XimServer::gDpy),
 			XFT_FAMILY, XftTypeString, "Sans",
 			XFT_PIXEL_SIZE, XftTypeDouble, (double)DEFAULT_FONT_SIZE,
-			NULL);
+			(char *)NULL);
     }
 }
 
@@ -112,7 +112,7 @@
 			DefaultScreen(XimServer::gDpy),
 			XFT_FAMILY, XftTypeString, fontname,
 			XFT_PIXEL_SIZE, XftTypeDouble, (double)DEFAULT_FONT_SIZE,
-			NULL);
+			(char *)NULL);
 	if (xftfont) {
 	    if (gXftFont)
 		XftFontClose(XimServer::gDpy, gXftFont);
@@ -387,7 +387,7 @@
 			    DefaultScreen(XimServer::gDpy),
 			    XFT_FAMILY, XftTypeString, gXftFontName,
 			    XFT_PIXEL_SIZE, XftTypeDouble, (double)mXftFontSize,
-			    NULL);
+			    (char *)NULL);
 	}
 	mXftDraw = XftDrawCreate(XimServer::gDpy, mPixmap,
 			DefaultVisual(XimServer::gDpy, scr_num),
@@ -557,7 +557,7 @@
 			    DefaultScreen(XimServer::gDpy),
 			    XFT_FAMILY, XftTypeString, gXftFontName,
 			    XFT_PIXEL_SIZE, XftTypeDouble, (double)size,
-			    NULL);
+			    (char *)NULL);
 	    mXftFontSize = size;
 	}
 }
