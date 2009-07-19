Index: bgpd/rde_update.c
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpd/rde_update.c,v
retrieving revision 1.1.1.1
retrieving revision 1.3
diff -u -p -r1.1.1.1 -r1.3
--- bgpd/rde_update.c	30 Jun 2009 05:46:15 -0000	1.1.1.1
+++ bgpd/rde_update.c	9 Jul 2009 17:22:14 -0000	1.3
@@ -1,4 +1,4 @@
-/*	$OpenBSD: rde_update.c,v 1.61 2007/11/27 01:13:54 claudio Exp $ */
+/*	$OpenBSD: rde_update.c,v 1.68 2009/06/06 01:10:29 claudio Exp $ */
 
 /*
  * Copyright (c) 2004 Claudio Jeker <claudio@openbsd.org>
@@ -17,10 +17,17 @@
  */
 #include <sys/types.h>
 #include <sys/queue.h>
+#if defined(__FreeBSD__)	/* sys/hash.h */
+#include "hash.h"
+#else
 #include <sys/hash.h>
+#endif /* defined(__FreeBSD__) */
 
 #include <stdlib.h>
 #include <string.h>
+#if defined(__FreeBSD__)	/* limits.h */
+#include <limits.h>
+#endif /* defined(__FreeBSD__) */
 
 #include "bgpd.h"
 #include "rde.h"
@@ -360,7 +367,7 @@ up_generate(struct rde_peer *peer, struc
 	if (asp) {
 		ua = calloc(1, sizeof(struct update_attr));
 		if (ua == NULL)
-			fatal("up_generate_updates");
+			fatal("up_generate");
 
 		if (up_generate_attr(peer, ua, asp, addr->af) == -1) {
 			log_warnx("generation of bgp path attributes failed");
@@ -379,7 +386,7 @@ up_generate(struct rde_peer *peer, struc
 
 	up = calloc(1, sizeof(struct update_prefix));
 	if (up == NULL)
-		fatal("up_generate_updates");
+		fatal("up_generate");
 	up->prefix = *addr;
 	up->prefixlen = prefixlen;
 
@@ -404,9 +411,9 @@ up_generate_updates(struct filter_head *
 			return;
 
 		pt_getaddr(old->prefix, &addr);
-		if (rde_filter(NULL, rules, peer, old->aspath, &addr,
-		    old->prefix->prefixlen, old->aspath->peer, DIR_OUT) ==
-		    ACTION_DENY)
+		if (rde_filter(peer->ribid, NULL, rules, peer, old->aspath,
+		    &addr, old->prefix->prefixlen, old->aspath->peer,
+		    DIR_OUT) == ACTION_DENY)
 			return;
 
 		/* withdraw prefix */
@@ -423,9 +430,9 @@ up_generate_updates(struct filter_head *
 		}
 
 		pt_getaddr(new->prefix, &addr);
-		if (rde_filter(&asp, rules, peer, new->aspath, &addr,
-		    new->prefix->prefixlen, new->aspath->peer, DIR_OUT) ==
-		    ACTION_DENY) {
+		if (rde_filter(peer->ribid, &asp, rules, peer, new->aspath,
+		    &addr, new->prefix->prefixlen, new->aspath->peer,
+		    DIR_OUT) == ACTION_DENY) {
 			path_put(asp);
 			up_generate_updates(rules, peer, NULL, old);
 			return;
@@ -473,8 +480,8 @@ up_generate_default(struct filter_head *
 	bzero(&addr, sizeof(addr));
 	addr.af = af;
 
-	if (rde_filter(&fasp, rules, peer, asp, &addr, 0, NULL, DIR_OUT) ==
-	    ACTION_DENY) {
+	if (rde_filter(peer->ribid, &fasp, rules, peer, asp, &addr, 0, NULL,
+	    DIR_OUT) == ACTION_DENY) {
 		path_put(fasp);
 		path_put(asp);
 		return;
@@ -617,7 +624,7 @@ up_generate_attr(struct rde_peer *peer, 
 	u_char		*pdata;
 	u_int32_t	 tmp32;
 	in_addr_t	 nexthop;
-	int		 r, ismp = 0, neednewpath = 0;
+	int		 flags, r, ismp = 0, neednewpath = 0;
 	u_int16_t	 len = sizeof(up_attr_buf), wlen = 0, plen;
 	u_int8_t	 l;
 
@@ -629,7 +636,7 @@ up_generate_attr(struct rde_peer *peer, 
 
 	/* aspath */
 	if (!peer->conf.ebgp ||
-	    rde_decisionflags() & BGPD_FLAG_DECISION_TRANS_AS)
+	    peer->conf.flags & PEERFLAG_TRANS_AS)
 		pdata = aspath_prepend(a->aspath, rde_local_as(), 0, &plen);
 	else
 		pdata = aspath_prepend(a->aspath, rde_local_as(), 1, &plen);
@@ -762,25 +769,29 @@ up_generate_attr(struct rde_peer *peer, 
 	/* NEW to OLD conversion when going sending stuff to a 2byte AS peer */
 	if (neednewpath) {
 		if (!peer->conf.ebgp ||
-		    rde_decisionflags() & BGPD_FLAG_DECISION_TRANS_AS)
+		    peer->conf.flags & PEERFLAG_TRANS_AS)
 			pdata = aspath_prepend(a->aspath, rde_local_as(), 0,
 			    &plen);
 		else
 			pdata = aspath_prepend(a->aspath, rde_local_as(), 1,
 			    &plen);
+		flags = ATTR_OPTIONAL|ATTR_TRANSITIVE;
+		if (!(a->flags & F_PREFIX_ANNOUNCED))
+			flags |= ATTR_PARTIAL;
 		if (plen == 0)
 			r = 0;
-		else if ((r = attr_write(up_attr_buf + wlen, len,
-		    ATTR_OPTIONAL|ATTR_TRANSITIVE, ATTR_NEW_ASPATH,
-		    pdata, plen)) == -1)
+		else if ((r = attr_write(up_attr_buf + wlen, len, flags,
+		    ATTR_AS4_PATH, pdata, plen)) == -1)
 			return (-1);
 		wlen += r; len -= r;
 		free(pdata);
 	}
 	if (newaggr) {
-		if ((r = attr_write(up_attr_buf + wlen, len,
-		    ATTR_OPTIONAL|ATTR_TRANSITIVE, ATTR_NEW_AGGREGATOR,
-		    newaggr->data, newaggr->len)) == -1)
+		flags = ATTR_OPTIONAL|ATTR_TRANSITIVE;
+		if (!(a->flags & F_PREFIX_ANNOUNCED))
+			flags |= ATTR_PARTIAL;
+		if ((r = attr_write(up_attr_buf + wlen, len, flags,
+		    ATTR_AS4_AGGREGATOR, newaggr->data, newaggr->len)) == -1)
 			return (-1);
 		wlen += r; len -= r;
 	}
@@ -913,13 +924,7 @@ up_dump_mp_unreach(u_char *buf, u_int16_
 		return (NULL);
 
 	datalen += 3;	/* afi + safi */
-	if (datalen > 255) {
-		attrlen += 2 + datalen;
-		flags |= ATTR_EXTLEN;
-	} else {
-		attrlen += 1 + datalen;
-		buf++;
-	}
+
 	/* prepend header, need to do it reverse */
 	/* safi & afi */
 	buf[--wpos] = SAFI_UNICAST;
@@ -929,11 +934,15 @@ up_dump_mp_unreach(u_char *buf, u_int16_
 
 	/* attribute length */
 	if (datalen > 255) {
+		attrlen += 2 + datalen;
+		flags |= ATTR_EXTLEN;
 		wpos -= sizeof(u_int16_t);
 		tmp = htons(datalen);
 		memcpy(buf + wpos, &tmp, sizeof(u_int16_t));
-	} else
+	} else {
+		attrlen += 1 + datalen;
 		buf[--wpos] = (u_char)datalen;
+	}
 
 	/* mp attribute */
 	buf[--wpos] = (u_char)ATTR_MP_UNREACH_NLRI;
@@ -954,7 +963,7 @@ up_dump_mp_unreach(u_char *buf, u_int16_
 	/* total length includes the two 2-bytes length fields. */
 	*len = attrlen + 2 * sizeof(u_int16_t);
 
-	return (buf);
+	return (buf + wpos);
 }
 
 u_char *
