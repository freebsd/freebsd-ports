--- src/MenuBox.cpp.orig	Fri Nov 12 13:27:47 2004
+++ src/MenuBox.cpp	Sat Nov 13 20:49:08 2004
@@ -16,7 +16,7 @@
 #include <wxVillaLib/ImageProc.h>
 #include <wxVillaLib/utils.h>
 #include <wxXML/xml.h>
-#include "math.h"
+#include <math.h>
 #include <wx/dnd.h>
 #include <wx/utils.h>
 #include <wx/mstream.h>
@@ -404,11 +404,11 @@
 
 bool MenuBox::MoveObject(int& x, int& y)
 {
-  x = (int) round(x/m_scale);
-  y = (int) round(y/m_scale);
+  x = rint(x/m_scale);
+  y = rint(y/m_scale);
   bool res = MoveObjectInt(x,y);
-  x = (int) round(x*m_scale);
-  y = (int) round(y*m_scale);
+  x = rint(x*m_scale);
+  y = rint(y*m_scale);
   return res;
 }
 
@@ -444,8 +444,8 @@
 
 bool MenuBox::ResizeObject(int x, int y, TransformType transformType)
 {
-  x = (int) round(x/m_scale);
-  y = (int) round(y/m_scale);
+  x = rint(x/m_scale);
+  y = rint(y/m_scale);
   return ResizeObjectInt(x, y, transformType);
 }
 
