--- libmpdemux/demux_rtp.cpp.orig	Thu Oct 17 00:15:43 2002
+++ libmpdemux/demux_rtp.cpp	Sat Dec 14 19:17:10 2002
@@ -314,7 +314,11 @@
     // block myself until one comes available:
     TaskScheduler& scheduler
       = bufferQueue->readSource()->envir().taskScheduler();
+#if USAGEENVIRONMENT_LIBRARY_VERSION_INT >= 1038614400
+    scheduler.doEventLoop(&bufferQueue->blockingFlag);
+#else
     scheduler.blockMyself(&bufferQueue->blockingFlag);
+#endif
   }
 
   if (demuxer->stream->eof) return 0; // source stream has closed down
