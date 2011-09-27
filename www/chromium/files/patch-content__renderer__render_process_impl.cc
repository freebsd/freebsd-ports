--- content/renderer/render_process_impl.cc.orig	2011-09-14 01:53:06.000000000 +0300
+++ content/renderer/render_process_impl.cc	2011-09-14 01:55:08.000000000 +0300
@@ -87,7 +87,7 @@
 
 bool RenderProcessImpl::InProcessPlugins() {
   const CommandLine& command_line = *CommandLine::ForCurrentProcess();
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
   // Plugin processes require a UI message loop, and the Linux message loop
   // implementation only allows one UI loop per process.
   if (command_line.HasSwitch(switches::kInProcessPlugins))
@@ -103,10 +103,10 @@
 // Platform specific code for dealing with bitmap transport...
 
 TransportDIB* RenderProcessImpl::CreateTransportDIB(size_t size) {
-#if defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_FREEBSD)
   // Windows and Linux create transport DIBs inside the renderer
   return TransportDIB::Create(size, transport_dib_next_sequence_number_++);
-#elif defined(OS_MACOSX)  // defined(OS_WIN) || defined(OS_LINUX)
+#elif defined(OS_MACOSX)  // defined(OS_WIN) || defined(OS_LINUX) || defined(OS_FREEBSD)
   // Mac creates transport DIBs in the browser, so we need to do a sync IPC to
   // get one.  The TransportDIB is cached in the browser.
   TransportDIB::Handle handle;
@@ -141,7 +141,7 @@
   int width = rect.width();
   int height = rect.height();
   const size_t stride = skia::PlatformCanvas::StrideForWidth(rect.width());
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
   const size_t max_size = base::SysInfo::MaxSharedMemorySize();
 #else
   const size_t max_size = 0;
