--- content/renderer/render_process_impl.cc.orig	2012-12-20 10:01:28.000000000 +0200
+++ content/renderer/render_process_impl.cc	2013-01-06 22:32:44.000000000 +0200
@@ -89,7 +89,7 @@
 
 bool RenderProcessImpl::InProcessPlugins() {
   const CommandLine& command_line = *CommandLine::ForCurrentProcess();
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Plugin processes require a UI message loop, and the Linux message loop
   // implementation only allows one UI loop per process.
   if (command_line.HasSwitch(switches::kInProcessPlugins))
@@ -114,7 +114,7 @@
 
 TransportDIB* RenderProcessImpl::CreateTransportDIB(size_t size) {
 #if defined(OS_WIN) || defined(OS_LINUX) || \
-    defined(OS_OPENBSD) || defined(OS_ANDROID)
+    defined(OS_BSD) || defined(OS_ANDROID)
   // Windows and Linux create transport DIBs inside the renderer
   return TransportDIB::Create(size, transport_dib_next_sequence_number_++);
 #elif defined(OS_MACOSX)
@@ -152,7 +152,7 @@
   int width = rect.width();
   int height = rect.height();
   const size_t stride = skia::PlatformCanvasStrideForWidth(rect.width());
-#if defined(OS_LINUX) || defined(OS_OPENBSD)
+#if defined(OS_LINUX) || defined(OS_BSD)
   const size_t max_size = base::SysInfo::MaxSharedMemorySize();
 #else
   const size_t max_size = 0;
