--- ./chrome/renderer/mock_render_thread.cc.orig	2010-12-16 02:11:59.000000000 +0100
+++ ./chrome/renderer/mock_render_thread.cc	2010-12-20 20:15:08.000000000 +0100
@@ -108,7 +108,7 @@
     IPC_MESSAGE_HANDLER(ViewHostMsg_AllocatePDFTransport,
                         OnAllocatePDFTransport)
 #endif
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
     IPC_MESSAGE_HANDLER(ViewHostMsg_AllocateTempFileForPrinting,
                         OnAllocateTempFileForPrinting)
     IPC_MESSAGE_HANDLER(ViewHostMsg_TempFileForPrintingWritten,
@@ -156,7 +156,7 @@
 }
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 void MockRenderThread::OnAllocateTempFileForPrinting(
     base::FileDescriptor* renderer_fd,
     int* browser_fd) {
