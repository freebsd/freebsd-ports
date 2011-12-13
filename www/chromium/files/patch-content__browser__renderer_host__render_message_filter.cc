--- content/browser/renderer_host/render_message_filter.cc.orig	2011-11-01 10:42:33.000000000 +0200
+++ content/browser/renderer_host/render_message_filter.cc	2011-11-21 21:16:01.000000000 +0200
@@ -348,7 +348,7 @@
                         OnCheckNotificationPermission)
     IPC_MESSAGE_HANDLER(ChildProcessHostMsg_SyncAllocateSharedMemory,
                         OnAllocateSharedMemory)
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_FREEBSD)
     IPC_MESSAGE_HANDLER(ViewHostMsg_AllocTransportDIB, OnAllocTransportDIB)
     IPC_MESSAGE_HANDLER(ViewHostMsg_FreeTransportDIB, OnFreeTransportDIB)
 #endif
@@ -656,7 +656,7 @@
   return context;
 }
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_FREEBSD)
 void RenderMessageFilter::OnAllocTransportDIB(
     size_t size, bool cache_in_browser, TransportDIB::Handle* handle) {
   render_widget_helper_->AllocTransportDIB(size, cache_in_browser, handle);
