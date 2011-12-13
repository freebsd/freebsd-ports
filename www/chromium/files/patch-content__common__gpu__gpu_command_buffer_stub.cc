--- content/common/gpu/gpu_command_buffer_stub.cc.orig	2011-11-30 21:36:25.000000000 +0200
+++ content/common/gpu/gpu_command_buffer_stub.cc	2011-11-30 21:36:49.000000000 +0200
@@ -193,7 +193,7 @@
         renderer_id_,
         route_id_,
         handle_);
-#elif defined(OS_WIN) || defined(OS_LINUX)
+#elif defined(OS_WIN) || defined(OS_LINUX) || defined(OS_FREEBSD)
     surface_ = gfx::GLSurface::CreateViewGLSurface(software_, handle_);
 #endif
   } else {
