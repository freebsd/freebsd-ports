--- DclockP.h.orig	2008-07-08 12:56:09.000000000 +0900
+++ DclockP.h	2012-10-07 23:57:24.000000000 +0900
@@ -9,7 +9,9 @@
 #include "Dclock.h"
 
 /* Add -DXFT_SUPPORT in the Imakefile for freefont support */
+#ifdef XFT_SUPPORT
 #include <X11/Xft/Xft.h>
+#endif
 
 
 typedef struct {
