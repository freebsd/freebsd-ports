--- src/3rdparty/chromium/ui/gl/gl_implementation.cc.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/ui/gl/gl_implementation.cc
@@ -123,7 +123,7 @@ GLImplementation GetNamedGLImplementation(const std::s
 
 GLImplementation GetSoftwareGLImplementation() {
 #if (defined(OS_WIN) ||                                                     \
-     (defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(USE_OZONE)) || \
+     ((defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS) && !defined(USE_OZONE)) || \
      (defined(OS_MACOSX) && defined(USE_EGL)))
   return kGLImplementationSwiftShaderGL;
 #else
