--- relayd/relay.c.orig	2010-05-27 11:10:01.121571779 +0200
+++ relayd/relay.c	2010-05-27 11:21:34.847047990 +0200
@@ -105,6 +105,7 @@
 		    char *, size_t);
 void		 relay_close_http(struct rsession *, u_int, const char *,
 		    u_int16_t);
+void		 relay_http_request_close(struct ctl_relay_event *);
 
 SSL_CTX		*relay_ssl_ctx_create(struct relay *);
 void		 relay_ssl_transaction(struct rsession *,
@@ -1312,6 +1313,29 @@
 }
 
 void
+relay_http_request_close(struct ctl_relay_event *cre)
+{
+	if (cre->path != NULL) {
+		free(cre->path);
+		cre->path = NULL;
+	}
+
+	cre->args = NULL;
+	cre->version = NULL;
+
+	if (cre->buf != NULL) {
+		free(cre->buf);
+		cre->buf = NULL;
+		cre->buflen = 0;
+	}
+
+	cre->line = 0;
+	cre->method = 0;
+	cre->done = 0;
+	cre->chunked = 0;
+}
+
+void
 relay_read_http(struct bufferevent *bev, void *arg)
 {
 	struct ctl_relay_event	*cre = (struct ctl_relay_event *)arg;
@@ -1580,10 +1604,7 @@
 		if (relay_bufferevent_print(cre->dst, "\r\n") == -1)
 			goto fail;
 
-		cre->line = 0;
-		cre->method = 0;
-		cre->done = 0;
-		cre->chunked = 0;
+		relay_http_request_close(cre);
 
  done:
 		if (cre->dir == RELAY_DIR_REQUEST && !cre->toread &&
