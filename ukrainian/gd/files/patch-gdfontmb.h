--- gdfontmb.h.orig	Tue Feb  6 21:44:02 2001
+++ gdfontmb.h	Fri May 18 13:11:09 2001
@@ -2,27 +2,20 @@
 #ifndef _GDFONTMB_H_
 #define _GDFONTMB_H_ 1
 
-#ifdef __cplusplus
-extern "C" {
-#endif
-
 /*
 	This is a header file for gd font, generated using
-	bdftogd version 0.5 by Jan Pazdziora, adelton@fi.muni.cz
+	bdftogd version 0.60 by Jan Pazdziora, adelton@fi.muni.cz
 	from bdf font
-	-misc-fixed-bold-r-normal-sans-13-94-100-100-c-70-iso8859-2
-	at Thu Jan  8 13:54:57 1998.
-	No copyright info was found in the original bdf.
+	-FreeType-Lucida Console-Medium-R-Normal--12-120-75-75-C-64-KOI8-U
+	at Fri May 18 13:10:25 2001.
+	The original bdf was holding following copyright:
+	"Copyright © 1993 Bigelow & Holmes Inc. All rights reserved."
  */
 
 
 #include "gd.h"
 
 extern gdFontPtr gdFontMediumBold;
-
-#ifdef __cplusplus
-}
-#endif
 
 #endif
 
