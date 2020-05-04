--- tools/xenstore/xenstored_core.h.orig	2019-12-17 14:23:09 UTC
+++ tools/xenstore/xenstored_core.h
@@ -204,7 +204,7 @@ void finish_daemonize(void);
 /* Open a pipe for signal handling */
 void init_pipe(int reopen_log_pipe[2]);
 
-xengnttab_handle **xgt_handle;
+extern xengnttab_handle **xgt_handle;
 
 int remember_string(struct hashtable *hash, const char *str);
 
