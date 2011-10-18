--- content/renderer/webplugin_delegate_proxy.cc.orig	2011-08-30 11:58:21.000000000 +0300
+++ content/renderer/webplugin_delegate_proxy.cc	2011-09-11 22:57:59.000000000 +0300
@@ -494,7 +494,7 @@
 static void CopyTransportDIBHandleForMessage(
     const TransportDIB::Handle& handle_in,
     TransportDIB::Handle* handle_out) {
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_FREEBSD)
   // On Mac, TransportDIB::Handle is typedef'ed to FileDescriptor, and
   // FileDescriptor message fields needs to remain valid until the message is
   // sent or else the sendmsg() call will fail.
@@ -644,12 +644,12 @@
     scoped_ptr<TransportDIB>* memory,
     scoped_ptr<skia::PlatformCanvas>* canvas) {
   const size_t size = BitmapSizeForPluginRect(plugin_rect_);
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_OPENBSD) && !defined(OS_FREEBSD)
   memory->reset(TransportDIB::Create(size, 0));
   if (!memory->get())
     return false;
 #endif
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_OPENBSD) || defined(OS_FREEBSD)
   TransportDIB::Handle handle;
   IPC::Message* msg = new ViewHostMsg_AllocTransportDIB(size, false, &handle);
   if (!RenderThread::current()->Send(msg))
