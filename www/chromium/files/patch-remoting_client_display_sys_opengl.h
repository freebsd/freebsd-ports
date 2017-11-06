--- remoting/client/display/sys_opengl.h.orig	2017-08-10 16:17:57.036915000 +0200
+++ remoting/client/display/sys_opengl.h	2017-08-10 16:18:06.520753000 +0200
@@ -9,7 +9,7 @@
 
 #if defined(OS_IOS)
 #include <OpenGLES/ES3/gl.h>
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #define GL_GLEXT_PROTOTYPES
 #include <GL/gl.h>
 #include <GL/glext.h>
