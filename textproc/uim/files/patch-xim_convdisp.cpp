--- xim/convdisp.cpp.orig	2013-06-30 04:26:09 UTC
+++ xim/convdisp.cpp
@@ -87,14 +87,14 @@ init_default_xftfont() {
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
 
@@ -112,7 +112,7 @@ update_default_xftfont() {
 			DefaultScreen(XimServer::gDpy),
 			XFT_FAMILY, XftTypeString, fontname,
 			XFT_PIXEL_SIZE, XftTypeDouble, (double)DEFAULT_FONT_SIZE,
-			NULL);
+			(char *)NULL);
 	if (xftfont) {
 	    if (gXftFont)
 		XftFontClose(XimServer::gDpy, gXftFont);
@@ -387,7 +387,7 @@ PeWin::PeWin(Window pw, const char *im_l
 			    DefaultScreen(XimServer::gDpy),
 			    XFT_FAMILY, XftTypeString, gXftFontName,
 			    XFT_PIXEL_SIZE, XftTypeDouble, (double)mXftFontSize,
-			    NULL);
+			    (char *)NULL);
 	}
 	mXftDraw = XftDrawCreate(XimServer::gDpy, mPixmap,
 			DefaultVisual(XimServer::gDpy, scr_num),
@@ -557,7 +557,7 @@ void PeWin::set_xftfont(const char *xfld
 			    DefaultScreen(XimServer::gDpy),
 			    XFT_FAMILY, XftTypeString, gXftFontName,
 			    XFT_PIXEL_SIZE, XftTypeDouble, (double)size,
-			    NULL);
+			    (char *)NULL);
 	    mXftFontSize = size;
 	}
 }
