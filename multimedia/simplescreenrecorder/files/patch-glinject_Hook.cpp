--- glinject/Hook.cpp.orig	2017-12-11 00:15:36 UTC
+++ glinject/Hook.cpp
@@ -15,6 +15,8 @@ THE SOFTWARE IS PROVIDED "AS IS" AND THE
 #include <GL/glx.h>
 #include <X11/X.h>
 
+extern char **environ;
+
 typedef void (*GLXextFuncPtr)(void);
 
 void InitGLInject();
