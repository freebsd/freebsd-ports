--- ../thotlib/internals/h/picture.h.orig	Thu Jun  2 07:12:22 2005
+++ ../thotlib/internals/h/picture.h	Mon Aug 15 16:39:55 2005
@@ -9,6 +9,8 @@
  * Definition for picture management
  */
 
+#include <gdk_imlib.h>
+
 #ifdef _WINGUI
 #include <windows.h>
 #endif /* _WINGUI */
