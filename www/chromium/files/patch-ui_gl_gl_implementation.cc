--- ui/gl/gl_implementation.cc.orig	2018-08-01 00:09:48.000000000 +0200
+++ ui/gl/gl_implementation.cc	2018-08-04 21:27:12.545235000 +0200
@@ -123,7 +123,7 @@
 
 GLImplementation GetSoftwareGLImplementation() {
 #if (defined(OS_WIN) ||                                                     \
-     (defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(USE_OZONE)) || \
+     ((defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS) && !defined(USE_OZONE)) || \
      (defined(OS_MACOSX) && defined(USE_EGL)))
   return kGLImplementationSwiftShaderGL;
 #else
