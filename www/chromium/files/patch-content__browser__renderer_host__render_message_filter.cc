--- content/browser/renderer_host/render_message_filter.cc.orig	2011-06-24 11:30:32.000000000 +0300
+++ content/browser/renderer_host/render_message_filter.cc	2011-06-26 20:58:31.256783053 +0300
@@ -360,7 +360,7 @@
                         OnCheckNotificationPermission)
     IPC_MESSAGE_HANDLER(ViewHostMsg_AllocateSharedMemoryBuffer,
                         OnAllocateSharedMemoryBuffer)
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_FREEBSD)
     IPC_MESSAGE_HANDLER(ViewHostMsg_AllocTransportDIB, OnAllocTransportDIB)
     IPC_MESSAGE_HANDLER(ViewHostMsg_FreeTransportDIB, OnFreeTransportDIB)
 #endif
@@ -647,7 +647,7 @@
   return context_getter->GetURLRequestContext();
 }
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_FREEBSD)
 void RenderMessageFilter::OnAllocTransportDIB(
     size_t size, bool cache_in_browser, TransportDIB::Handle* handle) {
   render_widget_helper_->AllocTransportDIB(size, cache_in_browser, handle);
