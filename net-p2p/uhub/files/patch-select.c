--- src/network/select.c.orig	2010-01-25 01:38:25.000000000 +0300
+++ src/network/select.c	2010-02-01 12:57:36.000000000 +0300
@@ -101,8 +101,8 @@
 	FD_ZERO(&g_backend->wfds);
 
 	size_t secs = timeout_queue_get_next_timeout(&g_backend->timeout_queue, g_backend->now);
-	tval.tv_secs = secs;
-	tval.tv_usecs = 0;
+	tval.tv_sec = secs;
+	tval.tv_usec = 0;
 
 	for (n = 0, found = 0; found < g_backend->num && n < g_backend->max; n++)
 	{
