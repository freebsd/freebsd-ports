--- ./qtvid.h.orig	2008-03-02 22:45:09.000000000 +0800
+++ ./qtvid.h	2008-03-02 22:46:14.000000000 +0800
@@ -42,6 +42,7 @@
 #define _CPhone_Qt_H
 
 #include <ptlib.h>
+#include <ptclib/delaychan.h>
 #include <qimage.h>
 #include "vdisplay.h"
 
@@ -319,6 +320,8 @@
 
   Rgb32Image *rgbImage;
   PMutex      bufferMutex;
+
+  PAdaptiveDelay m_pacing;
 };
 
     
