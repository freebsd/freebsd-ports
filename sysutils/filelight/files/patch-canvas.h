--- src/canvas.h.orig	Sat Aug 14 00:36:14 2004
+++ src/canvas.h	Sat Aug 14 00:36:19 2004
@@ -97,6 +97,8 @@
     KAction *m_actKonsole;
     KAction *m_actCenter;
     KAction *m_actRun;
+
+    friend class FileMap;
 };
 
 #endif
