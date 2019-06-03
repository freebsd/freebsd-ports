Index: bgpd/log.c
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpd/log.c,v
retrieving revision 1.1.1.5
retrieving revision 1.1.1.8
diff -u -p -r1.1.1.5 -r1.1.1.8
--- bgpd/log.c	14 Feb 2010 20:19:57 -0000	1.1.1.5
+++ bgpd/log.c	13 Oct 2012 18:22:43 -0000	1.1.1.8
@@ -1,4 +1,4 @@
-/*	$OpenBSD: log.c,v 1.50 2007/04/23 13:04:24 claudio Exp $ */
+/*	$OpenBSD: log.c,v 1.55 2011/08/20 19:02:28 sthen Exp $ */
 
 /*
  * Copyright (c) 2003, 2004 Henning Brauer <henning@openbsd.org>
@@ -32,6 +32,7 @@
 #include "log.h"
 
 int	debug;
+int	verbose;
 
 void	 logit(int, const char *, ...);
 
@@ -42,8 +43,9 @@ log_fmt_peer(const struct peer_config *p
 	char		*pfmt, *p;
 
 	ip = log_addr(&peer->remote_addr);
-	if ((peer->remote_addr.af == AF_INET && peer->remote_masklen != 32) ||
-	    (peer->remote_addr.af == AF_INET6 && peer->remote_masklen != 128)) {
+	if ((peer->remote_addr.aid == AID_INET && peer->remote_masklen != 32) ||
+	    (peer->remote_addr.aid == AID_INET6 &&
+	    peer->remote_masklen != 128)) {
 		if (asprintf(&p, "%s/%u", ip, peer->remote_masklen) == -1)
 			fatal(NULL);
 	} else {
@@ -77,6 +79,12 @@ log_init(int n_debug)
 }
 
 void
+log_verbose(int v)
+{
+	verbose = v;
+}
+
+void
 logit(int pri, const char *fmt, ...)
 {
 	va_list	ap;
@@ -193,7 +201,7 @@ log_debug(const char *emsg, ...)
 {
 	va_list	 ap;
 
-	if (debug) {
+	if (verbose) {
 		va_start(ap, emsg);
 		vlog(LOG_DEBUG, emsg, ap);
 		va_end(ap);
@@ -250,7 +258,7 @@ log_statechange(struct peer *peer, enum 
 
 void
 log_notification(const struct peer *peer, u_int8_t errcode, u_int8_t subcode,
-    u_char *data, u_int16_t datalen)
+    u_char *data, u_int16_t datalen, const char *dir)
 {
 	char		*p;
 	const char	*suberrname = NULL;
@@ -283,27 +291,31 @@ log_notification(const struct peer *peer
 			suberrname = suberr_cease_names[subcode];
 		break;
 	case ERR_HOLDTIMEREXPIRED:
-	case ERR_FSM:
 		uk = 1;
 		break;
+	case ERR_FSM:
+		if (subcode >= sizeof(suberr_fsm_names)/sizeof(char *))
+			uk = 1;
+		else
+			suberrname = suberr_fsm_names[subcode];
+		break;
 	default:
-		logit(LOG_CRIT, "%s: received notification, unknown errcode "
-		    "%u, subcode %u", p, errcode, subcode);
+		logit(LOG_CRIT, "%s: %s notification, unknown errcode "
+		    "%u, subcode %u", p, dir, errcode, subcode);
 		free(p);
 		return;
 	}
 
 	if (uk)
-		logit(LOG_CRIT,
-		    "%s: received notification: %s, unknown subcode %u",
-		    p, errnames[errcode], subcode);
+		logit(LOG_CRIT, "%s: %s notification: %s, unknown subcode %u",
+		    p, dir, errnames[errcode], subcode);
 	else {
 		if (suberrname == NULL)
-			logit(LOG_CRIT, "%s: received notification: %s",
-			    p, errnames[errcode]);
+			logit(LOG_CRIT, "%s: %s notification: %s", p,
+			    dir, errnames[errcode]);
 		else
-			logit(LOG_CRIT, "%s: received notification: %s, %s",
-			    p, errnames[errcode], suberrname);
+			logit(LOG_CRIT, "%s: %s notification: %s, %s",
+			    p, dir, errnames[errcode], suberrname);
 	}
 	free(p);
 }
@@ -318,6 +330,9 @@ log_conn_attempt(const struct peer *peer
 		b = log_sockaddr(sa);
 		logit(LOG_INFO, "connection from non-peer %s refused", b);
 	} else {
+		/* only log if there is a chance that the session may come up */
+		if (peer->conf.down && peer->state == STATE_IDLE)
+			return;
 		p = log_fmt_peer(&peer->conf);
 		logit(LOG_INFO, "Connection attempt from %s while session is "
 		    "in state %s", p, statenames[peer->state]);
