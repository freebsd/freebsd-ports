--- datatype/image/png/common/pxpngdec.cpp.orig	Wed Jul  9 21:13:55 2003
+++ datatype/image/png/common/pxpngdec.cpp	Sun May 23 00:50:47 2004
@@ -63,6 +63,8 @@
 #include "errdbg.h"
 #include "hxperf.h"
 
+void PNGAPI png_clear_invert_alpha(png_structp png_ptr);
+
 PXPNGDecode::PXPNGDecode()
 {
     m_lRefCount = 0;
