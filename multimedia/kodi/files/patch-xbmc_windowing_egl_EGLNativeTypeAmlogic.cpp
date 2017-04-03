--- xbmc/windowing/egl/EGLNativeTypeAmlogic.cpp.orig	2015-11-12 03:09:15 UTC
+++ xbmc/windowing/egl/EGLNativeTypeAmlogic.cpp
@@ -17,6 +17,7 @@
  *  <http://www.gnu.org/licenses/>.
  *
  */
+#if defined(__linux__)
 
 #include "EGLNativeTypeAmlogic.h"
 #include "guilib/gui3d.h"
@@ -305,3 +306,4 @@ void CEGLNativeTypeAmlogic::DisableFreeS
     close(fd0);
   }
 }
+#endif
