--- src/third_party/angle/src/libANGLE/renderer/gl/glx/FunctionsGLX.cpp.orig	2026-10-18 18:43:23 UTC
+++ src/third_party/angle/src/libANGLE/renderer/gl/glx/FunctionsGLX.cpp
@@ -153,10 +153,10 @@ bool FunctionsGLX::initialize(Display *x
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
