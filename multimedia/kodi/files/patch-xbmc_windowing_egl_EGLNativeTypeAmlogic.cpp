--- xbmc/windowing/egl/EGLNativeTypeAmlogic.cpp.orig	2017-11-14 16:55:01 UTC
+++ xbmc/windowing/egl/EGLNativeTypeAmlogic.cpp
@@ -17,6 +17,7 @@
  *  <http://www.gnu.org/licenses/>.
  *
  */
+#if defined(__linux__)
 
 #include "EGLNativeTypeAmlogic.h"
 #include "guilib/GraphicContext.h"
@@ -259,3 +260,4 @@ void CEGLNativeTypeAmlogic::SetFramebufferResolution(i
     close(fd0);
   }
 }
+#endif
