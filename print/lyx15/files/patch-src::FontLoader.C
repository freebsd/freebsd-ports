--- src/FontLoader.C.orig	Fri Mar 22 02:25:07 2002
+++ src/FontLoader.C	Fri Aug 23 03:38:09 2002
@@ -300,7 +300,8 @@
 		if (font == "fixed") {
 			lyxerr << "We're doomed. Can't get 'fixed' font." << endl;
 		} else {
-			lyxerr << "Could not get font. Using 'fixed'." << endl;
+			lyxerr << "Could not get font '" << font.c_str() <<
+				"'. Using 'fixed'." << endl;
 			fs = XLoadQueryFont(GUIRunTime::x11Display(), "fixed");
 		}
 	} else if (lyxerr.debugging(Debug::FONT)) {
