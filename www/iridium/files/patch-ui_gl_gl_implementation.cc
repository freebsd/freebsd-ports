--- ui/gl/gl_implementation.cc.orig	2018-05-09 21:06:41.000000000 +0200
+++ ui/gl/gl_implementation.cc	2018-08-16 15:08:00.138967000 +0200
@@ -121,7 +121,7 @@
 }
 
 GLImplementation GetSoftwareGLImplementation() {
-#if (defined(OS_WIN) || (defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(USE_OZONE)))
+#if (defined(OS_WIN) || ((defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS) && !defined(USE_OZONE)))
   return kGLImplementationSwiftShaderGL;
 #else
   return kGLImplementationOSMesaGL;
