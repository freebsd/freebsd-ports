--- gpu/command_buffer/tests/gl_oes_egl_image_unittest.cc.orig	2023-03-13 07:33:08 UTC
+++ gpu/command_buffer/tests/gl_oes_egl_image_unittest.cc
@@ -14,7 +14,7 @@
 #include "ui/gl/gl_image.h"
 #include "ui/gl/init/gl_factory.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "ui/gl/gl_image_native_pixmap.h"
 #endif
 
@@ -46,7 +46,7 @@ class GpuOESEGLImageTest : public testing::Test,
   bool egl_initialized_{false};
 };
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // TODO(crbug.com/835072): re-enable this test on ASAN once bugs are fixed.
 #if !defined(ADDRESS_SANITIZER)
 
