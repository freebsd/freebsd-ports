--- src/log.c.orig	Sat Nov 13 10:16:40 2004
+++ src/log.c	Sat Nov 13 10:17:24 2004
@@ -74,11 +74,12 @@
 void gaim_log_write(GaimLog *log, GaimMessageFlags type,
 		    const char *from, time_t time, const char *message)
 {
+	struct _gaim_logsize_user *lu;
+
 	g_return_if_fail(log);
 	g_return_if_fail(log->logger);
 	g_return_if_fail(log->logger->write);
 
-	struct _gaim_logsize_user *lu;
 	(log->logger->write)(log, type, from, time, message);
 
 	lu = g_new(struct _gaim_logsize_user, 1);
