--- logmsg.h.orig	2020-12-12 20:08:48.656485000 +0000
+++ logmsg.h	2020-12-12 20:09:08.664699000 +0000
@@ -15,8 +15,8 @@
 #define LOG_DEBUG       7       /* debug-level messages */
 
 
-int loglevel;               /* threshold for log messages relevance */
-char *logprefix;
+extern int loglevel;               /* threshold for log messages relevance */
+extern char *logprefix;
 
 int logmsg_init(const char *prefix);
 int logmsg(int prio, char *fmt, ...);
