--- xim/convdisp.cpp.orig	2022-03-18 00:54:17 UTC
+++ xim/convdisp.cpp
@@ -81,14 +81,14 @@ init_default_xftfont() {
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
 
@@ -106,7 +106,7 @@ update_default_xftfont() {
 			DefaultScreen(XimServer::gDpy),
 			XFT_FAMILY, XftTypeString, fontname,
 			XFT_PIXEL_SIZE, XftTypeDouble, (double)DEFAULT_FONT_SIZE,
-			NULL);
+			(char *)NULL);
 	if (xftfont) {
 	    if (gXftFont)
 		XftFontClose(XimServer::gDpy, gXftFont);
@@ -385,7 +385,7 @@ PeWin::PeWin(Window pw, const char *im_lang, const cha
 			    DefaultScreen(XimServer::gDpy),
 			    XFT_FAMILY, XftTypeString, gXftFontName,
 			    XFT_PIXEL_SIZE, XftTypeDouble, (double)mXftFontSize,
-			    NULL);
+			    (char *)NULL);
 	}
 	mXftDraw = XftDrawCreate(XimServer::gDpy, mPixmap,
 			DefaultVisual(XimServer::gDpy, scr_num),
@@ -555,7 +555,7 @@ void PeWin::set_xftfont(const char *xfld)
 			    DefaultScreen(XimServer::gDpy),
 			    XFT_FAMILY, XftTypeString, gXftFontName,
 			    XFT_PIXEL_SIZE, XftTypeDouble, (double)size,
-			    NULL);
+			    (char *)NULL);
 	    mXftFontSize = size;
 	}
 }
