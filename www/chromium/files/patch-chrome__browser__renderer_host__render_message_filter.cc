--- chrome/browser/renderer_host/render_message_filter.cc.orig	2011-03-23 00:59:35.959798938 +0200
+++ chrome/browser/renderer_host/render_message_filter.cc	2011-03-23 00:59:46.644644079 +0200
@@ -375,7 +375,7 @@
     IPC_MESSAGE_HANDLER_DELAY_REPLY(ViewHostMsg_GetDefaultPrintSettings,
                                     OnGetDefaultPrintSettings)
     IPC_MESSAGE_HANDLER_DELAY_REPLY(ViewHostMsg_ScriptedPrint, OnScriptedPrint)
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_FREEBSD)
     IPC_MESSAGE_HANDLER(ViewHostMsg_AllocTransportDIB, OnAllocTransportDIB)
     IPC_MESSAGE_HANDLER(ViewHostMsg_FreeTransportDIB, OnFreeTransportDIB)
 #endif
@@ -1196,7 +1196,7 @@
   HistogramSynchronizer::DeserializeHistogramList(sequence_number, histograms);
 }
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_FREEBSD)
 void RenderMessageFilter::OnAllocTransportDIB(
     size_t size, bool cache_in_browser, TransportDIB::Handle* handle) {
   render_widget_helper_->AllocTransportDIB(size, cache_in_browser, handle);
