--- src/modules/module-rt.c.orig	2026-03-16 11:54:17 UTC
+++ src/modules/module-rt.c
@@ -138,9 +138,6 @@ PW_LOG_TOPIC_STATIC(mod_topic, "mod." NAME);
 #define REALTIME_POLICY         SCHED_FIFO
 
 /* FreeBSD compat */
-#ifndef SCHED_RESET_ON_FORK
-#define SCHED_RESET_ON_FORK 0
-#endif
 
 #ifndef RLIMIT_RTTIME
 #define RLIMIT_RTTIME 15
