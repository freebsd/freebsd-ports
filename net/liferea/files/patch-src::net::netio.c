--- src/net/netio.c.orig	2005-04-10 17:43:21.000000000 +0300
+++ src/net/netio.c	2005-04-10 17:45:17.000000000 +0300
@@ -1065,5 +1065,6 @@
 	g_free(cur_ptr.authinfo);
 	g_free(cur_ptr.cookies);
 	debug4(DEBUG_UPDATE, "download result - HTTP status: %d, error: %d, netio error:%d, data: %d", request->httpstatus, cur_ptr.problem, cur_ptr.netio_error, request->data);
+	free(cur_ptr.content_type);
 	return;
 }
