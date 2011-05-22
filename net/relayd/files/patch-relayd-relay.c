--- relayd/relay.c.orig	2011-05-20 11:43:53.000000000 +0200
+++ relayd/relay.c	2011-05-22 10:41:40.085208004 +0200
@@ -16,7 +16,11 @@
  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
  */
 
+#ifdef __FreeBSD__
+#include <sys/param.h>
+#else
 #include <sys/types.h>
+#endif
 #include <sys/queue.h>
 #include <sys/time.h>
 #include <sys/stat.h>
@@ -77,7 +81,9 @@
 
 void		 relay_write(struct bufferevent *, void *);
 void		 relay_read(struct bufferevent *, void *);
+#ifndef __FreeBSD__
 int		 relay_splicelen(struct ctl_relay_event *);
+#endif
 void		 relay_error(struct bufferevent *, short, void *);
 void		 relay_dump(struct ctl_relay_event *, const void *, size_t);
 
@@ -494,6 +500,7 @@
 	return (0);
 }
 
+#ifndef __FreeBSD__
 in_port_t
 relay_socket_getport(struct sockaddr_storage *ss)
 {
@@ -509,6 +516,7 @@
 	/* NOTREACHED */
 	return (0);
 }
+#endif
 
 int
 relay_socket(struct sockaddr_storage *ss, in_port_t port,
@@ -577,6 +585,7 @@
 		    &val, sizeof(val)) == -1)
 			goto bad;
 	}
+#ifndef __FreeBSD__
 	if (proto->tcpflags & (TCPFLAG_SACK|TCPFLAG_NSACK)) {
 		if (proto->tcpflags & TCPFLAG_NSACK)
 			val = 0;
@@ -586,6 +595,7 @@
 		    &val, sizeof(val)) == -1)
 			goto bad;
 	}
+#endif
 
 	return (s);
 
@@ -675,6 +685,7 @@
 		}
 		break;
 	case RELAY_PROTO_TCP:
+#ifndef __FreeBSD__
 		if ((proto->tcpflags & TCPFLAG_NSPLICE) ||
 		    (rlay->rl_conf.flags & (F_SSL|F_SSLCLIENT)))
 			break;
@@ -692,6 +703,7 @@
 			return;
 		}
 		con->se_out.splicelen = 0;
+#endif
 		break;
 	default:
 		fatalx("relay_input: unknown protocol");
@@ -935,12 +947,20 @@
 	}
 	if (strstr(val, "$TIMEOUT") != NULL) {
 		snprintf(ibuf, sizeof(ibuf), "%lu",
+#ifdef __FreeBSD__
+		    (unsigned long)rlay->rl_conf.timeout.tv_sec);
+#else
 		    rlay->rl_conf.timeout.tv_sec);
+#endif
 		if (expand_string(buf, len, "$TIMEOUT", ibuf) != 0)
 			return (NULL);
 	}
 
+#ifndef __FreeBSD__
 	return (buf);
+#else
+	return (char *)(buf);
+#endif
 }
 
 int
@@ -1552,7 +1572,11 @@
 	switch (type) {
 	case DIGEST_SHA1:
 	case DIGEST_MD5:
+#ifdef __FreeBSD__
+		if ((md = digeststr(type, (u_int8_t*)val, strlen(val), NULL)) == NULL) {
+#else
 		if ((md = digeststr(type, val, strlen(val), NULL)) == NULL) {
+#endif
 			relay_close_http(con, 500,
 			    "failed to allocate digest", 0);
 			goto fail;
@@ -1841,6 +1865,7 @@
 	}
 }
 
+#ifndef __FreeBSD__
 int
 relay_splicelen(struct ctl_relay_event *cre)
 {
@@ -1859,6 +1884,7 @@
 	}
 	return (0);
 }
+#endif
 
 void
 relay_error(struct bufferevent *bev, short error, void *arg)
@@ -1866,9 +1892,12 @@
 	struct ctl_relay_event *cre = (struct ctl_relay_event *)arg;
 	struct rsession *con = cre->con;
 	struct evbuffer *dst;
+#ifndef __FreeBSD__
 	struct timeval tv, tv_now;
+#endif
 
 	if (error & EVBUFFER_TIMEOUT) {
+#ifndef __FreeBSD__
 		if (gettimeofday(&tv_now, NULL) == -1) {
 			relay_close(con, strerror(errno));
 			return;
@@ -1882,6 +1911,9 @@
 			relay_close(con, "buffer event timeout");
 		else
 			bufferevent_enable(cre->bev, EV_READ);
+#else
+		relay_close(con, "buffer event timeout");
+#endif
 		return;
 	}
 	if (error & (EVBUFFER_READ|EVBUFFER_WRITE|EVBUFFER_EOF)) {
@@ -1934,8 +1966,10 @@
 	con->se_out.dst = &con->se_in;
 	con->se_in.con = con;
 	con->se_out.con = con;
+#ifndef __FreeBSD__
 	con->se_in.splicelen = -1;
 	con->se_out.splicelen = -1;
+#endif
 	con->se_relay = rlay;
 	con->se_id = ++relay_conid;
 	con->se_relayid = rlay->rl_conf.id;
@@ -1981,6 +2015,7 @@
 		return;
 	}
 
+#ifndef __FreeBSD__
 	if (rlay->rl_conf.flags & F_DIVERT) {
 		slen = sizeof(con->se_out.ss);
 		if (getsockname(s, (struct sockaddr *)&con->se_out.ss,
@@ -1996,12 +2031,19 @@
 		    con->se_out.port == rlay->rl_conf.port)
 			con->se_out.ss.ss_family = AF_UNSPEC;
 	} else if (rlay->rl_conf.flags & F_NATLOOK) {
+#else
+	if (rlay->rl_conf.flags & F_NATLOOK) {
+#endif
 		if ((cnl = (struct ctl_natlook *)
 		    calloc(1, sizeof(struct ctl_natlook))) == NULL) {
 			relay_close(con, "failed to allocate nat lookup");
 			return;
 		}
+#ifdef __FreeBSD__
+	}
 
+	if (rlay->rl_conf.flags & F_NATLOOK && cnl != NULL) {
+#endif
 		con->se_cnl = cnl;
 		bzero(cnl, sizeof(*cnl));
 		cnl->in = -1;
@@ -2605,8 +2647,12 @@
 		goto err;
 
 	/* Set session context to the local relay name */
-	if (!SSL_CTX_set_session_id_context(ctx, rlay->rl_conf.name,
-	    strlen(rlay->rl_conf.name)))
+	if (!SSL_CTX_set_session_id_context(ctx,
+#ifdef __FreeBSD__
+	    (unsigned char*)rlay->rl_conf.name, strlen(rlay->rl_conf.name)))
+#else
+	    rlay->rl_conf.name, strlen(rlay->rl_conf.name)))
+#endif
 		goto err;
 
 	return (ctx);
@@ -2623,7 +2669,7 @@
 {
 	struct relay		*rlay = (struct relay *)con->se_relay;
 	SSL			*ssl;
-	const SSL_METHOD	*method;
+	SSL_METHOD		*method;
 	void			(*cb)(int, short, void *);
 	u_int			 flags = EV_TIMEOUT;
 
@@ -3069,7 +3115,11 @@
 	if (fstat(fd, &st) != 0)
 		goto fail;
 	size = st.st_size;
+#ifndef __FreeBSD__
 	if ((buf = (char *)calloc(1, size + 1)) == NULL)
+#else
+	if ((buf = (u_int8_t *)calloc(1, size + 1)) == NULL)
+#endif
 		goto fail;
 	if (read(fd, buf, size) != size)
 		goto fail;
@@ -3077,7 +3127,11 @@
 	close(fd);
 
 	*len = size;
+#ifndef __FreeBSD__
 	return (buf);
+#else
+	return (char *)(buf);
+#endif
 
  fail:
 	if (buf != NULL)
@@ -3107,7 +3161,7 @@
 		return (-1);
 
 	if (snprintf(certfile, sizeof(certfile),
-	    "/etc/ssl/%s.crt", hbuf) == -1)
+	    "%%PREFIX%%/etc/ssl/%s.crt", hbuf) == -1)
 		return (-1);
 	if ((rlay->rl_ssl_cert = relay_load_file(certfile,
 	    &rlay->rl_conf.ssl_cert_len)) == NULL)
@@ -3115,7 +3169,7 @@
 	log_debug("%s: using certificate %s", __func__, certfile);
 
 	if (snprintf(certfile, sizeof(certfile),
-	    "/etc/ssl/private/%s.key", hbuf) == -1)
+	    "%%PREFIX%%/etc/ssl/private/%s.key", hbuf) == -1)
 		return -1;
 	if ((rlay->rl_ssl_key = relay_load_file(certfile,
 	    &rlay->rl_conf.ssl_key_len)) == NULL)
