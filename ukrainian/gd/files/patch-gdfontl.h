--- gdfontl.h.orig	Tue Feb  6 21:44:01 2001
+++ gdfontl.h	Fri May 18 13:11:09 2001
@@ -2,29 +2,20 @@
 #ifndef _GDFONTL_H_
 #define _GDFONTL_H_ 1
 
-#ifdef __cplusplus
-extern "C" {
-#endif
-
 /*
 	This is a header file for gd font, generated using
-	bdftogd version 0.5 by Jan Pazdziora, adelton@fi.muni.cz
+	bdftogd version 0.60 by Jan Pazdziora, adelton@fi.muni.cz
 	from bdf font
-	-misc-fixed-medium-r-normal--16-140-75-75-c-80-iso8859-2
-	at Tue Jan  6 19:39:27 1998.
-
+	-FreeType-Lucida Console-Medium-R-Normal--17-160-75-75-C-78-KOI8-U
+	at Fri May 18 13:10:26 2001.
 	The original bdf was holding following copyright:
-	"Libor Skarvada, libor@informatics.muni.cz"
+	"Copyright © 1993 Bigelow & Holmes Inc. All rights reserved."
  */
 
 
 #include "gd.h"
 
 extern gdFontPtr gdFontLarge;
-
-#ifdef __cplusplus
-}
-#endif
 
 #endif
 
