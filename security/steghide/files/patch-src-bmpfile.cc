--- src/bmpfile.cc.orig	Thu Sep 26 21:46:06 2002
+++ src/bmpfile.cc	Thu Sep 26 21:54:46 2002
@@ -21,6 +21,8 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <assert.h>
+#include <string>
+#include <vector>
 
 #include <libintl.h>
 #define _(S) gettext (S)
@@ -305,7 +307,7 @@
 			bmi_win.ncolors = bmi_win.bmih.biClrUsed ;
 		}
 
-		bmi_win.colors = vector<RGBQUAD> (bmi_win.ncolors) ;
+		bmi_win.colors = std::vector<RGBQUAD> (bmi_win.ncolors) ;
 		for (unsigned int i = 0 ; i < bmi_win.ncolors ; i++) {
 			bmi_win.colors[i].rgbBlue = getBinIO()->read8() ;
 			bmi_win.colors[i].rgbGreen = getBinIO()->read8() ;
@@ -371,7 +373,7 @@
 			}
 		}
 
-		bmi_os2.colors = vector<RGBTRIPLE> (bmi_os2.ncolors) ;
+		bmi_os2.colors = std::vector<RGBTRIPLE> (bmi_os2.ncolors) ;
 		for (unsigned int i = 0 ; i < bmi_os2.ncolors ; i++) {
 			bmi_os2.colors[i].rgbtBlue = getBinIO()->read8() ;
 			bmi_os2.colors[i].rgbtGreen = getBinIO()->read8() ;
@@ -550,7 +552,7 @@
 			paddinglength = 4 - (linelength % 4) ;
 		}
 
-		bitmap = vector<vector<unsigned char> > (height) ;
+		bitmap = std::vector<std::vector<unsigned char> > (height) ;
 		for (long line = height - 1 ; line >= 0 ; line--) {
 			for (long posinline = 0 ; posinline < linelength ; posinline++) {
 				bitmap[line].push_back (getBinIO()->read8()) ;
@@ -622,7 +624,7 @@
 			}
 		}
 
-		for (vector<unsigned char>::iterator i = atend.begin() ; i != atend.end() ; i++) {
+		for (std::vector<unsigned char>::iterator i = atend.begin() ; i != atend.end() ; i++) {
 			getBinIO()->write8 (*i) ;
 		}
 	}
