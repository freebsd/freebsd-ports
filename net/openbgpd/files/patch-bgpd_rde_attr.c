Index: bgpd/rde_attr.c
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpd/rde_attr.c,v
retrieving revision 1.1.1.6
retrieving revision 1.5
diff -u -p -r1.1.1.6 -r1.5
--- bgpd/rde_attr.c	14 Feb 2010 20:19:57 -0000	1.1.1.6
+++ bgpd/rde_attr.c	10 Apr 2010 12:16:23 -0000	1.5
@@ -1,4 +1,4 @@
-/*	$OpenBSD: rde_attr.c,v 1.79 2009/03/19 06:52:59 claudio Exp $ */
+/*	$OpenBSD: rde_attr.c,v 1.83 2010/03/29 09:24:07 claudio Exp $ */
 
 /*
  * Copyright (c) 2004 Claudio Jeker <claudio@openbsd.org>
@@ -17,7 +17,11 @@
  */
 
 #include <sys/types.h>
+#if defined(__FreeBSD__)	/* sys/hash.h */
+#include "hash.h"
+#else
 #include <sys/hash.h>
+#endif /* defined(__FreeBSD__) */
 #include <sys/queue.h>
 
 #include <netinet/in.h>
@@ -25,6 +29,9 @@
 #include <stdlib.h>
 #include <stdio.h>
 #include <string.h>
+#if defined(__FreeBSD__)	/* limits.h */
+#include <limits.h>
+#endif /* defined(__FreeBSD__) */
 
 #include "bgpd.h"
 #include "rde.h"
@@ -971,15 +978,26 @@ aspath_match(struct aspath *a, enum as_s
 	return (0);
 }
 
+/*
+ * Functions handling communities and extended communities.
+ */
+
+int community_ext_matchone(struct filter_extcommunity *, u_int16_t, u_int64_t);
+
 int
-community_match(void *data, u_int16_t len, int as, int type)
+community_match(struct rde_aspath *asp, int as, int type)
 {
-	u_int8_t	*p = data;
-	u_int16_t	 eas, etype;
+	struct attr	*a;
+	u_int8_t	*p;
+	u_int16_t	 eas, etype, len;
 
-	len >>= 2; /* divide by four */
+	a = attr_optget(asp, ATTR_COMMUNITIES);
+	if (a == NULL)
+		/* no communities, no match */
+		return (0);
 
-	for (; len > 0; len--) {
+	p = a->data;
+	for (len = a->len / 4; len > 0; len--) {
 		eas = *p++;
 		eas <<= 8;
 		eas |= *p++;
@@ -1000,7 +1018,6 @@ community_set(struct rde_aspath *asp, in
 	u_int8_t	*p = NULL;
 	unsigned int	 i, ncommunities = 0;
 	u_int8_t	 f = ATTR_OPTIONAL|ATTR_TRANSITIVE;
-	u_int8_t	 t = ATTR_COMMUNITIES;
 
 	attr = attr_optget(asp, ATTR_COMMUNITIES);
 	if (attr != NULL) {
@@ -1017,7 +1034,7 @@ community_set(struct rde_aspath *asp, in
 		p += 4;
 	}
 
-	if (ncommunities++ >= 0x3fff)
+	if (ncommunities++ >= USHRT_MAX / 4)
 		/* overflow */
 		return (0);
 
@@ -1032,11 +1049,10 @@ community_set(struct rde_aspath *asp, in
 	if (attr != NULL) {
 		memcpy(p + 4, attr->data, attr->len);
 		f = attr->flags;
-		t = attr->type;
 		attr_free(asp, attr);
 	}
 
-	attr_optadd(asp, f, t, p, ncommunities << 2);
+	attr_optadd(asp, f, ATTR_COMMUNITIES, p, ncommunities << 2);
 
 	free(p);
 	return (1);
@@ -1049,7 +1065,7 @@ community_delete(struct rde_aspath *asp,
 	u_int8_t	*p, *n;
 	u_int16_t	 l, len = 0;
 	u_int16_t	 eas, etype;
-	u_int8_t	 f, t;
+	u_int8_t	 f;
 
 	attr = attr_optget(asp, ATTR_COMMUNITIES);
 	if (attr == NULL)
@@ -1100,10 +1116,250 @@ community_delete(struct rde_aspath *asp,
 	}
 
 	f = attr->flags;
-	t = attr->type;
 
 	attr_free(asp, attr);
-	attr_optadd(asp, f, t, n, len);
+	attr_optadd(asp, f, ATTR_COMMUNITIES, n, len);
+	free(n);
+}
+
+int
+community_ext_match(struct rde_aspath *asp, struct filter_extcommunity *c,
+    u_int16_t neighas)
+{
+	struct attr	*attr;
+	u_int8_t	*p;
+	u_int64_t	 ec;
+	u_int16_t	 len;
+
+	attr = attr_optget(asp, ATTR_EXT_COMMUNITIES);
+	if (attr == NULL)
+		/* no communities, no match */
+		return (0);
+
+	p = attr->data;
+	for (len = attr->len / sizeof(ec); len > 0; len--) {
+		memcpy(&ec, p, sizeof(ec));
+		if (community_ext_matchone(c, neighas, ec))
+			return (1);
+		p += sizeof(ec);
+	}
+
+	return (0);
+}
+
+int
+community_ext_set(struct rde_aspath *asp, struct filter_extcommunity *c,
+    u_int16_t neighas)
+{
+	struct attr	*attr;
+	u_int8_t	*p = NULL;
+	u_int64_t	 community;
+	unsigned int	 i, ncommunities = 0;
+	u_int8_t	 f = ATTR_OPTIONAL|ATTR_TRANSITIVE;
+
+	if (community_ext_conv(c, neighas, &community))
+		return (0);
+
+	attr = attr_optget(asp, ATTR_EXT_COMMUNITIES);
+	if (attr != NULL) {
+		p = attr->data;
+		ncommunities = attr->len / sizeof(community);
+	}
+
+	/* first check if the community is not already set */
+	for (i = 0; i < ncommunities; i++) {
+		if (memcmp(&community, p, sizeof(community)) == 0)
+			/* already present, nothing todo */
+			return (1);
+		p += sizeof(community);
+	}
+
+	if (ncommunities++ >= USHRT_MAX / sizeof(community))
+		/* overflow */
+		return (0);
+
+	if ((p = malloc(ncommunities * sizeof(community))) == NULL)
+		fatal("community_ext_set");
+
+	memcpy(p, &community, sizeof(community));
+	if (attr != NULL) {
+		memcpy(p + sizeof(community), attr->data, attr->len);
+		f = attr->flags;
+		attr_free(asp, attr);
+	}
+
+	attr_optadd(asp, f, ATTR_EXT_COMMUNITIES, p,
+	    ncommunities * sizeof(community));
+
+	free(p);
+	return (1);
+}
+
+void
+community_ext_delete(struct rde_aspath *asp, struct filter_extcommunity *c,
+    u_int16_t neighas)
+{
+	struct attr	*attr;
+	u_int8_t	*p, *n;
+	u_int64_t	 community;
+	u_int16_t	 l, len = 0;
+	u_int8_t	 f;
+
+	if (community_ext_conv(c, neighas, &community))
+		return;
+
+	attr = attr_optget(asp, ATTR_EXT_COMMUNITIES);
+	if (attr == NULL)
+		/* no attr nothing to do */
+		return;
+
+	p = attr->data;
+	for (l = 0; l < attr->len; l += sizeof(community)) {
+		if (memcmp(&community, p + l, sizeof(community)) == 0)
+			/* match */
+			continue;
+		len += sizeof(community);
+	}
+
+	if (len == 0) {
+		attr_free(asp, attr);
+		return;
+	}
+
+	if ((n = malloc(len)) == NULL)
+		fatal("community_delete");
+
+	p = attr->data;
+	for (l = 0; l < len && p < attr->data + attr->len;
+	    p += sizeof(community)) {
+		if (memcmp(&community, p, sizeof(community)) == 0)
+			/* match */
+			continue;
+		memcpy(n + l, p, sizeof(community));
+		l += sizeof(community);
+	}
+
+	f = attr->flags;
+
+	attr_free(asp, attr);
+	attr_optadd(asp, f, ATTR_EXT_COMMUNITIES, n, len);
 	free(n);
 }
 
+int
+community_ext_conv(struct filter_extcommunity *c, u_int16_t neighas,
+    u_int64_t *community)
+{
+	u_int64_t	com;
+	u_int32_t	ip;
+
+	com = (u_int64_t)c->type << 56;
+	switch (c->type & EXT_COMMUNITY_VALUE) {
+	case EXT_COMMUNITY_TWO_AS:
+		com |= (u_int64_t)c->subtype << 48;
+		com |= (u_int64_t)c->data.ext_as.as << 32;
+		com |= c->data.ext_as.val;
+		break;
+	case EXT_COMMUNITY_IPV4:
+		com |= (u_int64_t)c->subtype << 48;
+		ip = ntohl(c->data.ext_ip.addr.s_addr);
+		com |= (u_int64_t)ip << 16;
+		com |= c->data.ext_ip.val;
+		break;
+	case EXT_COMMUNITY_FOUR_AS:
+		com |= (u_int64_t)c->subtype << 48;
+		com |= (u_int64_t)c->data.ext_as4.as4 << 16;
+		com |= c->data.ext_as4.val;
+		break;
+	case EXT_COMMUNITY_OPAQUE:
+		com |= (u_int64_t)c->subtype << 48;
+		com |= c->data.ext_opaq & EXT_COMMUNITY_OPAQUE_MAX;
+		break;
+	default:
+		com |= c->data.ext_opaq & 0xffffffffffffffULL;
+		break;
+	}
+
+	*community = htobe64(com);
+
+	return (0);
+}
+
+int
+community_ext_matchone(struct filter_extcommunity *c, u_int16_t neighas,
+    u_int64_t community)
+{
+	u_int64_t	com, mask;
+	u_int32_t	ip;
+
+	community = betoh64(community);
+
+	com = (u_int64_t)c->type << 56;
+	mask = 0xffULL << 56;
+	if ((com & mask) != (community & mask))
+		return (0);
+
+	switch (c->type & EXT_COMMUNITY_VALUE) {
+	case EXT_COMMUNITY_TWO_AS:
+	case EXT_COMMUNITY_IPV4:
+	case EXT_COMMUNITY_FOUR_AS:
+	case EXT_COMMUNITY_OPAQUE:
+		com = (u_int64_t)c->subtype << 48;
+		mask = 0xffULL << 48;
+		if ((com & mask) != (community & mask))
+			return (0);
+		break;
+	default:
+		com = c->data.ext_opaq & 0xffffffffffffffULL;
+		mask = 0xffffffffffffffULL;
+		if ((com & mask) == (community & mask))
+			return (1);
+		return (0);
+	}
+
+
+	switch (c->type & EXT_COMMUNITY_VALUE) {
+	case EXT_COMMUNITY_TWO_AS:
+		com = (u_int64_t)c->data.ext_as.as << 32;
+		mask = 0xffffULL << 32;
+		if ((com & mask) != (community & mask))
+			return (0);
+
+		com = c->data.ext_as.val;
+		mask = 0xffffffffULL;
+		if ((com & mask) == (community & mask))
+			return (1);
+		break;
+	case EXT_COMMUNITY_IPV4:
+		ip = ntohl(c->data.ext_ip.addr.s_addr);
+		com = (u_int64_t)ip << 16;
+		mask = 0xffffffff0000ULL;
+		if ((com & mask) != (community & mask))
+			return (0);
+
+		com = c->data.ext_ip.val;
+		mask = 0xffff;
+		if ((com & mask) == (community & mask))
+			return (1);
+		break;
+	case EXT_COMMUNITY_FOUR_AS:
+		com = (u_int64_t)c->data.ext_as4.as4 << 16;
+		mask = 0xffffffffULL << 16;
+		if ((com & mask) != (community & mask))
+			return (0);
+
+		com = c->data.ext_as4.val;
+		mask = 0xffff;
+		if ((com & mask) == (community & mask))
+			return (1);
+		break;
+	case EXT_COMMUNITY_OPAQUE:
+		com = c->data.ext_opaq & EXT_COMMUNITY_OPAQUE_MAX;
+		mask = EXT_COMMUNITY_OPAQUE_MAX;
+		if ((com & mask) == (community & mask))
+			return (1);
+		break;
+	}
+
+	return (0);
+}
