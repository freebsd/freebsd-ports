--- logrotate.h.orig	2017-10-12 15:19:41 UTC
+++ logrotate.h
@@ -80,7 +80,7 @@
     TAILQ_ENTRY(logInfo) list;
 };
 
-TAILQ_HEAD(logInfoHead, logInfo) logs;
+TAILQ_HEAD(logInfoHead, logInfo);
 
 extern int numLogs;
 extern int debug;
