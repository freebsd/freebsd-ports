--- ui/gl/gl_implementation.cc.orig	2017-12-24 20:24:43.427221000 +0100
+++ ui/gl/gl_implementation.cc	2017-12-24 20:25:40.159567000 +0100
@@ -104,7 +104,7 @@
 }
 
 GLImplementation GetSoftwareGLImplementation() {
-#if (defined(OS_WIN) || (defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(USE_OZONE)))
+#if (defined(OS_WIN) || ((defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS) && !defined(USE_OZONE)))
   return kGLImplementationSwiftShaderGL;
 #else
   return kGLImplementationOSMesaGL;
