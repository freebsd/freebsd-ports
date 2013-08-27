--- content/renderer/render_process_impl.cc.orig	2013-08-09 19:07:03.000000000 +0000
+++ content/renderer/render_process_impl.cc	2013-08-12 21:00:44.000000000 +0000
@@ -89,7 +89,7 @@
 
 bool RenderProcessImpl::InProcessPlugins() {
   const CommandLine& command_line = *CommandLine::ForCurrentProcess();
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Plugin processes require a UI message loop, and the Linux message loop
   // implementation only allows one UI loop per process.
   if (command_line.HasSwitch(switches::kInProcessPlugins))
@@ -152,7 +152,7 @@
   int width = rect.width();
   int height = rect.height();
   const size_t stride = skia::PlatformCanvasStrideForWidth(rect.width());
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
   const size_t max_size = base::SysInfo::MaxSharedMemorySize();
 #else
   const size_t max_size = 0;
