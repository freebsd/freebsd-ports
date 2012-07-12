--- content/renderer/webplugin_delegate_proxy.cc.orig	2012-05-30 10:01:23.000000000 +0300
+++ content/renderer/webplugin_delegate_proxy.cc	2012-06-05 22:20:29.000000000 +0300
@@ -491,7 +491,7 @@
     const TransportDIB::Handle& handle_in,
     TransportDIB::Handle* handle_out,
     base::ProcessId peer_pid) {
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_FREEBSD)
   // On Mac, TransportDIB::Handle is typedef'ed to FileDescriptor, and
   // FileDescriptor message fields needs to remain valid until the message is
   // sent or else the sendmsg() call will fail.
@@ -651,12 +651,12 @@
     scoped_ptr<TransportDIB>* memory,
     scoped_ptr<skia::PlatformCanvas>* canvas) {
   const size_t size = BitmapSizeForPluginRect(plugin_rect_);
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_FREEBSD)
   memory->reset(TransportDIB::Create(size, 0));
   if (!memory->get())
     return false;
 #endif
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_FREEBSD)
   TransportDIB::Handle handle;
   IPC::Message* msg = new ViewHostMsg_AllocTransportDIB(size, false, &handle);
   if (!RenderThreadImpl::current()->Send(msg))
