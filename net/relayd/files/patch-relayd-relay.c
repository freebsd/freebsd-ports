--- relayd/relay.c.orig	2011-01-15 01:22:35.236684399 +0100
+++ relayd/relay.c	2011-01-15 01:24:07.864955572 +0100
@@ -28,7 +28,6 @@
 #include <sys/un.h>
 #include <sys/tree.h>
 #include <sys/hash.h>
-#include <sys/resource.h>
 
 #include <net/if.h>
 #include <netinet/in_systm.h>
@@ -64,7 +63,7 @@
 void		 relay_init(void);
 void		 relay_launch(void);
 int		 relay_socket(struct sockaddr_storage *, in_port_t,
-		    struct protocol *, int);
+		    struct protocol *, int, int);
 int		 relay_socket_listen(struct sockaddr_storage *, in_port_t,
 		    struct protocol *);
 int		 relay_socket_connect(struct sockaddr_storage *, in_port_t,
@@ -105,6 +104,7 @@
 		    char *, size_t);
 void		 relay_close_http(struct rsession *, u_int, const char *,
 		    u_int16_t);
+void		 relay_http_request_close(struct ctl_relay_event *);
 
 SSL_CTX		*relay_ssl_ctx_create(struct relay *);
 void		 relay_ssl_transaction(struct rsession *,
@@ -148,6 +148,14 @@
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
 
@@ -158,8 +166,6 @@
 {
 	pid_t		 pid;
 	struct passwd	*pw;
-	struct event	 ev_sigint;
-	struct event	 ev_sigterm;
 	int		 i;
 
 	switch (pid = fork()) {
@@ -213,12 +219,17 @@
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
@@ -452,19 +463,9 @@
 	struct relay	*rlay;
 	struct host	*host;
 	struct timeval	 tv;
-	struct rlimit	 rl;
 
-	if (getrlimit(RLIMIT_NOFILE, &rl) == -1)
-		fatal("relay_init: failed to get resource limit");
-	log_debug("relay_init: max open files %d", rl.rlim_max);
-
-	/*
-	 * Allow the maximum number of open file descriptors for this
-	 * login class (which should be the class "daemon" by default).
-	 */
-	rl.rlim_cur = rl.rlim_max;
-	if (setrlimit(RLIMIT_NOFILE, &rl) == -1)
-		fatal("relay_init: failed to set resource limit");
+	/* Unlimited file descriptors (use system limits) */
+	socket_rlimit(-1);
 
 	TAILQ_FOREACH(rlay, env->sc_relays, rl_entry) {
 		if ((rlay->rl_conf.flags & (F_SSL|F_SSLCLIENT)) &&
@@ -625,7 +626,7 @@
 
 int
 relay_socket(struct sockaddr_storage *ss, in_port_t port,
-    struct protocol *proto, int fd)
+    struct protocol *proto, int fd, int reuseport)
 {
 	int s = -1, val;
 	struct linger lng;
@@ -643,9 +644,12 @@
 	bzero(&lng, sizeof(lng));
 	if (setsockopt(s, SOL_SOCKET, SO_LINGER, &lng, sizeof(lng)) == -1)
 		goto bad;
-	val = 1;
-	if (setsockopt(s, SOL_SOCKET, SO_REUSEPORT, &val, sizeof(int)) == -1)
-		goto bad;
+	if (reuseport) {
+		val = 1;
+		if (setsockopt(s, SOL_SOCKET, SO_REUSEPORT, &val,
+			sizeof(int)) == -1)
+			goto bad;
+	}
 	if (fcntl(s, F_SETFL, O_NONBLOCK) == -1)
 		goto bad;
 	if (proto->tcpflags & TCPFLAG_BUFSIZ) {
@@ -713,7 +717,7 @@
 {
 	int	s;
 
-	if ((s = relay_socket(ss, port, proto, fd)) == -1)
+	if ((s = relay_socket(ss, port, proto, fd, 0)) == -1)
 		return (-1);
 
 	if (connect(s, (struct sockaddr *)ss, ss->ss_len) == -1) {
@@ -734,7 +738,7 @@
 {
 	int s;
 
-	if ((s = relay_socket(ss, port, proto, -1)) == -1)
+	if ((s = relay_socket(ss, port, proto, -1, 1)) == -1)
 		return (-1);
 
 	if (bind(s, (struct sockaddr *)ss, ss->ss_len) == -1)
@@ -1312,6 +1316,29 @@
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
@@ -1580,10 +1607,7 @@
 		if (relay_bufferevent_print(cre->dst, "\r\n") == -1)
 			goto fail;
 
-		cre->line = 0;
-		cre->method = 0;
-		cre->done = 0;
-		cre->chunked = 0;
+		relay_http_request_close(cre);
 
  done:
 		if (cre->dir == RELAY_DIR_REQUEST && !cre->toread &&
@@ -2380,6 +2404,12 @@
 		bufferevent_free(con->se_out.bev);
 	else if (con->se_out.output != NULL)
 		evbuffer_free(con->se_out.output);
+	if (con->se_out.ssl != NULL) {
+		/* XXX handle non-blocking shutdown */
+		if (SSL_shutdown(con->se_out.ssl) == 0)
+			SSL_shutdown(con->se_out.ssl);
+		SSL_free(con->se_out.ssl);
+	}
 	if (con->se_out.s != -1)
 		close(con->se_out.s);
 	if (con->se_out.path != NULL)
@@ -2419,6 +2449,7 @@
 	struct table		*table;
 	struct ctl_status	 st;
 	objid_t			 id;
+	int			 verbose;
 
 	iev = ptr;
 	ibuf = &iev->ibuf;
@@ -2522,6 +2553,10 @@
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
