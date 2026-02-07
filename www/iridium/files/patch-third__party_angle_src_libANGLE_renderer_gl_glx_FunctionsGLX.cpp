--- third_party/angle/src/libANGLE/renderer/gl/glx/FunctionsGLX.cpp.orig	2025-12-10 15:04:57 UTC
+++ third_party/angle/src/libANGLE/renderer/gl/glx/FunctionsGLX.cpp
@@ -144,10 +144,10 @@ bool FunctionsGLX::initialize(Display *xDisplay, int s
     // which a GLXWindow was ever created.
     if (!sLibHandle)
     {
-        sLibHandle = dlopen("libGL.so.1", RTLD_NOW);
+        sLibHandle = dlopen("libGL.so", RTLD_NOW);
         if (!sLibHandle)
         {
-            *errorString = std::string("Could not dlopen libGL.so.1: ") + dlerror();
+            *errorString = std::string("Could not dlopen libGL.so: ") + dlerror();
             return false;
         }
     }
