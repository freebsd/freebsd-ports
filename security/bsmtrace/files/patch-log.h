--- log.h.orig	2020-08-23 21:49:13 UTC
+++ log.h
@@ -30,7 +30,7 @@
 #ifndef LOG_H_
 #define LOG_H_
 
-TAILQ_HEAD(, logchannel) log_head;
+extern TAILQ_HEAD(logchannel_head, logchannel) log_head;
 
 enum {
 	LOG_CHANNEL_NOP,
