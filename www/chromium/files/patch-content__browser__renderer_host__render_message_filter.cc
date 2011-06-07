--- content/browser/renderer_host/render_message_filter.cc.orig	2011-05-06 12:02:54.000000000 +0300
+++ content/browser/renderer_host/render_message_filter.cc	2011-06-04 15:22:29.321379253 +0300
@@ -365,7 +365,7 @@
     IPC_MESSAGE_HANDLER(ViewHostMsg_AllocateSharedMemoryBuffer,
                         OnAllocateSharedMemoryBuffer)
     IPC_MESSAGE_HANDLER(ViewHostMsg_DidZoomURL, OnDidZoomURL)
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_FREEBSD)
     IPC_MESSAGE_HANDLER(ViewHostMsg_AllocTransportDIB, OnAllocTransportDIB)
     IPC_MESSAGE_HANDLER(ViewHostMsg_FreeTransportDIB, OnFreeTransportDIB)
 #endif
@@ -740,7 +740,7 @@
       context_getter->GetURLRequestContext());
 }
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_FREEBSD)
 void RenderMessageFilter::OnAllocTransportDIB(
     size_t size, bool cache_in_browser, TransportDIB::Handle* handle) {
   render_widget_helper_->AllocTransportDIB(size, cache_in_browser, handle);
