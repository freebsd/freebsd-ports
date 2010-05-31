--- relayd/relay.c.orig	2010-05-31 09:13:05.908338459 +0200
+++ relayd/relay.c	2010-05-31 09:12:54.131616372 +0200
@@ -105,6 +105,7 @@
 		    char *, size_t);
 void		 relay_close_http(struct rsession *, u_int, const char *,
 		    u_int16_t);
+void		 relay_http_request_close(struct ctl_relay_event *);
 
 SSL_CTX		*relay_ssl_ctx_create(struct relay *);
 void		 relay_ssl_transaction(struct rsession *,
@@ -148,6 +149,14 @@
 	case SIGTERM:
 	case SIGINT:
 		(void)event_loopexit(NULL);
+		break;
+	case SIGCHLD:
+	case SIGHUP:
+	case SIGPIPE:
+		/* ignore */
+		break;
+	default:
+		fatalx("relay_sig_handler: unexpected signal");
 	}
 }
 
@@ -158,8 +167,6 @@
 {
 	pid_t		 pid;
 	struct passwd	*pw;
-	struct event	 ev_sigint;
-	struct event	 ev_sigterm;
 	int		 i;
 
 	switch (pid = fork()) {
@@ -213,12 +220,17 @@
 	/* Per-child initialization */
 	relay_init();
 
-	signal_set(&ev_sigint, SIGINT, relay_sig_handler, NULL);
-	signal_set(&ev_sigterm, SIGTERM, relay_sig_handler, NULL);
-	signal_add(&ev_sigint, NULL);
-	signal_add(&ev_sigterm, NULL);
-	signal(SIGHUP, SIG_IGN);
-	signal(SIGPIPE, SIG_IGN);
+	signal_set(&env->sc_evsigint, SIGINT, relay_sig_handler, env);
+	signal_set(&env->sc_evsigterm, SIGTERM, relay_sig_handler, env);
+	signal_set(&env->sc_evsigchld, SIGCHLD, relay_sig_handler, env);
+	signal_set(&env->sc_evsighup, SIGHUP, relay_sig_handler, env);
+	signal_set(&env->sc_evsigpipe, SIGPIPE, relay_sig_handler, env);
+
+	signal_add(&env->sc_evsigint, NULL);
+	signal_add(&env->sc_evsigterm, NULL);
+	signal_add(&env->sc_evsigchld, NULL);
+	signal_add(&env->sc_evsighup, NULL);
+	signal_add(&env->sc_evsigpipe, NULL);
 
 	/* setup pipes */
 	close(pipe_pfe2hce[0]);
@@ -1312,6 +1324,29 @@
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
@@ -1580,10 +1615,7 @@
 		if (relay_bufferevent_print(cre->dst, "\r\n") == -1)
 			goto fail;
 
-		cre->line = 0;
-		cre->method = 0;
-		cre->done = 0;
-		cre->chunked = 0;
+		relay_http_request_close(cre);
 
  done:
 		if (cre->dir == RELAY_DIR_REQUEST && !cre->toread &&
@@ -2419,6 +2451,7 @@
 	struct table		*table;
 	struct ctl_status	 st;
 	objid_t			 id;
+	int			 verbose;
 
 	iev = ptr;
 	ibuf = &iev->ibuf;
@@ -2522,6 +2555,10 @@
 			imsg_compose_event(iev, IMSG_CTL_END,
 			    0, 0, -1, NULL, 0);
 			break;
+		case IMSG_CTL_LOG_VERBOSE:
+			memcpy(&verbose, imsg.data, sizeof(verbose));
+			log_verbose(verbose);
+			break;
 		default:
 			log_debug("relay_dispatch_msg: unexpected imsg %d",
 			    imsg.hdr.type);
