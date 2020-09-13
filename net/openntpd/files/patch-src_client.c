--- src/client.c.orig	2017-10-30 08:57:40 UTC
+++ src/client.c
@@ -1,4 +1,4 @@
-/*	$OpenBSD: client.c,v 1.105 2017/05/30 23:30:48 benno Exp $ */
+/*	$OpenBSD: client.c,v 1.114 2020/09/11 07:09:41 otto Exp $ */
 
 /*
  * Copyright (c) 2003, 2004 Henning Brauer <henning@openbsd.org>
@@ -215,6 +215,12 @@ client_query(struct ntp_peer *p)
 	return (0);
 }
 
+
+/*
+ * -1: Not processed, not an NTP message (e.g. icmp induced  ECONNREFUSED)
+ *  0: Not prrocessed due to validation issues
+ *  1: NTP message validated and processed
+ */
 int
 client_dispatch(struct ntp_peer *p, u_int8_t settime)
 {
@@ -231,7 +237,7 @@ client_dispatch(struct ntp_peer *p, u_int8_t settime)
 	struct cmsghdr		*cmsg;
 #endif
 	ssize_t			 size;
-	double			 T1, T2, T3, T4;
+	double			 T1, T2, T3, T4, offset, delay;
 	time_t			 interval;
 
 	memset(&somsg, 0, sizeof(somsg));
@@ -249,7 +255,7 @@ client_dispatch(struct ntp_peer *p, u_int8_t settime)
 		    errno == ENOPROTOOPT || errno == ENOENT) {
 			client_log_error(p, "recvmsg", errno);
 			set_next(p, error_interval());
-			return (0);
+			return (-1);
 		} else
 			fatal("recvfrom");
 	}
@@ -391,14 +397,6 @@ client_dispatch(struct ntp_peer *p, u_int8_t settime)
 	} else
 		p->reply[p->shift].status.send_refid = msg.xmttime.fractionl;
 
-	if (p->trustlevel < TRUSTLEVEL_PATHETIC)
-		interval = scale_interval(INTERVAL_QUERY_PATHETIC);
-	else if (p->trustlevel < TRUSTLEVEL_AGGRESSIVE)
-		interval = scale_interval(INTERVAL_QUERY_AGGRESSIVE);
-	else
-		interval = scale_interval(INTERVAL_QUERY_NORMAL);
-
-	set_next(p, interval);
 	p->state = STATE_REPLY_RECEIVED;
 
 	/* every received reply which we do not discard increases trust */
@@ -410,20 +408,32 @@ client_dispatch(struct ntp_peer *p, u_int8_t settime)
 		p->trustlevel++;
 	}
 
+	offset = p->reply[p->shift].offset;
+	delay = p->reply[p->shift].delay;
+
+	client_update(p);
+	if (settime)
+		priv_settime(p->reply[p->shift].offset);
+
+	if (p->trustlevel < TRUSTLEVEL_PATHETIC)
+		interval = scale_interval(INTERVAL_QUERY_PATHETIC);
+	else if (p->trustlevel < TRUSTLEVEL_AGGRESSIVE)
+		interval = scale_interval(INTERVAL_QUERY_AGGRESSIVE);
+	else
+		interval = scale_interval(INTERVAL_QUERY_NORMAL);
+
 	log_debug("reply from %s: offset %f delay %f, "
 	    "next query %llds",
 	    log_sockaddr((struct sockaddr *)&p->addr->ss),
-	    p->reply[p->shift].offset, p->reply[p->shift].delay,
+	    offset, delay,
 	    (long long)interval);
 
-	client_update(p);
-	if (settime)
-		priv_settime(p->reply[p->shift].offset);
+	set_next(p, interval);
 
 	if (++p->shift >= OFFSET_ARRAY_SIZE)
 		p->shift = 0;
 
-	return (0);
+	return (1);
 }
 
 int
