--- gdfonts.h.orig	Tue Feb  6 21:44:02 2001
+++ gdfonts.h	Fri May 18 13:11:09 2001
@@ -2,27 +2,20 @@
 #ifndef _GDFONTS_H_
 #define _GDFONTS_H_ 1
 
-#ifdef __cplusplus
-extern "C" {
-#endif
-
 /*
 	This is a header file for gd font, generated using
-	bdftogd version 0.5 by Jan Pazdziora, adelton@fi.muni.cz
+	bdftogd version 0.60 by Jan Pazdziora, adelton@fi.muni.cz
 	from bdf font
-	-misc-fixed-medium-r-semicondensed-sans-12-116-75-75-c-60-iso8859-2
-	at Thu Jan  8 14:13:20 1998.
-	No copyright info was found in the original bdf.
+	-FreeType-Lucida Console-Medium-R-Normal--11-110-75-75-C-57-KOI8-U
+	at Fri May 18 13:10:24 2001.
+	The original bdf was holding following copyright:
+	"Copyright © 1993 Bigelow & Holmes Inc. All rights reserved."
  */
 
 
 #include "gd.h"
 
 extern gdFontPtr gdFontSmall;
-
-#ifdef __cplusplus
-}
-#endif
 
 #endif
 
