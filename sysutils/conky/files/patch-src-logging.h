--- src/logging.h.orig
+++ src/logging.h
@@ -30,6 +30,7 @@
 #include "mail.h"
 
 void clean_up(void *memtofree1, void* memtofree2);
+void clean_up_without_threads(void *memtofree1, void* memtofree2);
 
 #ifndef _LOGGING_H
 #define _LOGGING_H
@@ -44,6 +45,9 @@ void clean_up(void *memtofree1, void* memtofree2);
 #define CRIT_ERR(memtofree1, memtofree2, ...) \
 	{ NORM_ERR(__VA_ARGS__); clean_up(memtofree1, memtofree2); free(current_mail_spool); exit(EXIT_FAILURE); }
 
+#define THREAD_CRIT_ERR(memtofree1, memtofree2, ...) \
+	{ NORM_ERR(__VA_ARGS__); clean_up_without_threads(memtofree1, memtofree2); free(current_mail_spool); return; }
+
 /* debugging output */
 extern int global_debug_level;
 #define __DBGP(level, ...) \
