--- src/MenuBox.cpp.orig	Fri Aug  6 19:32:13 2004
+++ src/MenuBox.cpp	Fri Aug  6 19:41:00 2004
@@ -15,7 +15,7 @@
 #include "MPEG.h"
 #include <wxVillaLib/ImageProc.h>
 #include <wxVillaLib/utils.h>
-#include "math.h"
+#include <math.h>
 #include <wx/dnd.h>
 #include <wx/utils.h>
 
@@ -374,11 +374,11 @@
 
 void MenuBox::MoveObject(int& x, int& y)
 {
-  x = (int) round(x/m_scale);
-  y = (int) round(y/m_scale);
+  x = rint(x/m_scale);
+  y = rint(y/m_scale);
   MoveObjectInt(x,y);
-  x = (int) round(x*m_scale);
-  y = (int) round(y*m_scale);
+  x = rint(x*m_scale);
+  y = rint(y*m_scale);
 }
 
 void MenuBox::MoveObjectInt(int& x, int& y)
@@ -411,8 +411,8 @@
 
 void MenuBox::ResizeObject(int x, int y, TransformType transformType)
 {
-  x = (int) round(x/m_scale);
-  y = (int) round(y/m_scale);
+  x = rint(x/m_scale);
+  y = rint(y/m_scale);
   ResizeObjectInt(x, y, transformType);
 }
 
