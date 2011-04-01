--- ./chrome/renderer/render_process_impl.cc.orig	2010-12-16 02:11:59.000000000 +0100
+++ ./chrome/renderer/render_process_impl.cc	2010-12-20 20:15:08.000000000 +0100
@@ -243,7 +243,7 @@
 #if defined(OS_WIN) || defined(OS_LINUX)
   // Windows and Linux create transport DIBs inside the renderer
   return TransportDIB::Create(size, transport_dib_next_sequence_number_++);
-#elif defined(OS_MACOSX)  // defined(OS_WIN) || defined(OS_LINUX)
+#elif defined(OS_MACOSX) || defined(OS_FREEBSD) // defined(OS_WIN) || defined(OS_LINUX)
   // Mac creates transport DIBs in the browser, so we need to do a sync IPC to
   // get one.  The TransportDIB is cached in the browser.
   TransportDIB::Handle handle;
@@ -260,7 +260,7 @@
   if (!dib)
     return;
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_FREEBSD)
   // On Mac we need to tell the browser that it can drop a reference to the
   // shared memory.
   IPC::Message* msg = new ViewHostMsg_FreeTransportDIB(dib->id());
@@ -278,7 +278,7 @@
   int width = rect.width();
   int height = rect.height();
   const size_t stride = skia::PlatformCanvas::StrideForWidth(rect.width());
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
   const size_t max_size = base::SysInfo::MaxSharedMemorySize();
 #else
   const size_t max_size = 0;
