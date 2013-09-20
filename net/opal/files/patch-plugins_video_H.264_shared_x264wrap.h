--- plugins/video/H.264/shared/x264wrap.h.orig	2013-07-09 00:34:36.000000000 +0200
+++ plugins/video/H.264/shared/x264wrap.h	2013-07-09 00:38:14.000000000 +0200
@@ -126,7 +126,7 @@
     char  m_ulName[100];
     int   m_pipeToProcess;
     int   m_pipeFromProcess;
-    pid_t m_pid;
+    int m_pid;
   #endif // WIN32
 
     bool m_startNewFrame;
