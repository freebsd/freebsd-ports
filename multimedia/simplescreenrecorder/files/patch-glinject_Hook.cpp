--- glinject/Hook.cpp.orig	2017-07-25 22:43:33 UTC
+++ glinject/Hook.cpp
@@ -15,6 +15,8 @@ THE SOFTWARE IS PROVIDED "AS IS" AND THE
 #include <GL/glx.h>
 #include <X11/X.h>
 
+extern char **environ;
+
 typedef void (*GLXextFuncPtr)(void);
 
 void InitGLInject();
