Index: bgpd/rde_attr.c
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpd/rde_attr.c,v
retrieving revision 1.1.1.6
retrieving revision 1.7
diff -u -p -r1.1.1.6 -r1.7
--- bgpd/rde_attr.c	14 Feb 2010 20:19:57 -0000	1.1.1.6
+++ bgpd/rde_attr.c	13 Oct 2012 18:36:00 -0000	1.7
@@ -1,4 +1,4 @@
-/*	$OpenBSD: rde_attr.c,v 1.79 2009/03/19 06:52:59 claudio Exp $ */
+/*	$OpenBSD: rde_attr.c,v 1.90 2012/04/12 17:27:20 claudio Exp $ */
 
 /*
  * Copyright (c) 2004 Claudio Jeker <claudio@openbsd.org>
@@ -17,14 +17,22 @@
  */
 
 #include <sys/types.h>
+#if defined(__FreeBSD__)	/* sys/hash.h */
+#include "hash.h"
+#else
 #include <sys/hash.h>
+#endif /* defined(__FreeBSD__) */
 #include <sys/queue.h>
 
 #include <netinet/in.h>
 
+#include <limits.h>
 #include <stdlib.h>
 #include <stdio.h>
 #include <string.h>
+#if defined(__FreeBSD__)	/* limits.h */
+#include <limits.h>
+#endif /* defined(__FreeBSD__) */
 
 #include "bgpd.h"
 #include "rde.h"
@@ -36,12 +44,12 @@ attr_write(void *p, u_int16_t p_len, u_i
 	u_char		*b = p;
 	u_int16_t	 tmp, tot_len = 2; /* attribute header (without len) */
 
+	flags &= ~ATTR_DEFMASK;
 	if (data_len > 255) {
 		tot_len += 2 + data_len;
 		flags |= ATTR_EXTLEN;
 	} else {
 		tot_len += 1 + data_len;
-		flags &= ~ATTR_EXTLEN;
 	}
 
 	if (tot_len > p_len)
@@ -63,26 +71,26 @@ attr_write(void *p, u_int16_t p_len, u_i
 }
 
 int
-attr_writebuf(struct buf *buf, u_int8_t flags, u_int8_t type, void *data,
+attr_writebuf(struct ibuf *buf, u_int8_t flags, u_int8_t type, void *data,
     u_int16_t data_len)
 {
 	u_char	hdr[4];
 
+	flags &= ~ATTR_DEFMASK;
 	if (data_len > 255) {
 		flags |= ATTR_EXTLEN;
 		hdr[2] = (data_len >> 8) & 0xff;
 		hdr[3] = data_len & 0xff;
 	} else {
-		flags &= ~ATTR_EXTLEN;
 		hdr[2] = data_len & 0xff;
 	}
 
 	hdr[0] = flags;
 	hdr[1] = type;
 
-	if (buf_add(buf, hdr, flags & ATTR_EXTLEN ? 4 : 3) == -1)
+	if (ibuf_add(buf, hdr, flags & ATTR_EXTLEN ? 4 : 3) == -1)
 		return (-1);
-	if (buf_add(buf, data, data_len) == -1)
+	if (ibuf_add(buf, data, data_len) == -1)
 		return (-1);
 	return (0);
 }
@@ -146,8 +154,11 @@ attr_optadd(struct rde_aspath *asp, u_in
 	for (l = 0; l < asp->others_len; l++) {
 		if (asp->others[l] == NULL)
 			break;
-		if (type == asp->others[l]->type)
+		if (type == asp->others[l]->type) {
+			if (a->refcnt == 0)
+				attr_put(a);
 			return (-1);
+		}
 	}
 
 	/* add attribute to the table but first bump refcnt */
@@ -318,6 +329,7 @@ attr_alloc(u_int8_t flags, u_int8_t type
 		fatal("attr_optadd");
 	rdemem.attr_cnt++;
 
+	flags &= ~ATTR_DEFMASK;	/* normalize mask */
 	a->flags = flags;
 	a->hash = hash32_buf(&flags, sizeof(flags), HASHINIT);
 	a->type = type;
@@ -347,6 +359,7 @@ attr_lookup(u_int8_t flags, u_int8_t typ
 	struct attr		*a;
 	u_int32_t		 hash;
 
+	flags &= ~ATTR_DEFMASK;	/* normalize mask */
 	hash = hash32_buf(&flags, sizeof(flags), HASHINIT);
 	hash = hash32_buf(&type, sizeof(type), hash);
 	hash = hash32_buf(&len, sizeof(len), hash);
@@ -405,6 +418,7 @@ aspath_verify(void *data, u_int16_t len,
 	u_int8_t	*seg = data;
 	u_int16_t	 seg_size, as_size = 2;
 	u_int8_t	 seg_len, seg_type;
+	int		 err = 0;
 
 	if (len & 1)
 		/* odd length aspath are invalid */
@@ -419,7 +433,15 @@ aspath_verify(void *data, u_int16_t len,
 		seg_type = seg[0];
 		seg_len = seg[1];
 
-		if (seg_type != AS_SET && seg_type != AS_SEQUENCE)
+		/*
+		 * BGP confederations should not show up but consider them
+		 * as a soft error which invalidates the path but keeps the
+		 * bgp session running.
+		 */
+		if (seg_type == AS_CONFED_SEQUENCE || seg_type == AS_CONFED_SET)
+			err = AS_ERR_SOFT;
+		if (seg_type != AS_SET && seg_type != AS_SEQUENCE &&
+		    seg_type != AS_CONFED_SEQUENCE && seg_type != AS_CONFED_SET)
 			return (AS_ERR_TYPE);
 
 		seg_size = 2 + as_size * seg_len;
@@ -431,7 +453,7 @@ aspath_verify(void *data, u_int16_t len,
 			/* empty aspath segments are not allowed */
 			return (AS_ERR_BAD);
 	}
-	return (0);	/* aspath is valid but probably not loop free */
+	return (err);	/* aspath is valid but probably not loop free */
 }
 
 void
@@ -762,15 +784,9 @@ aspath_countcopy(struct aspath *aspath, 
 u_int32_t
 aspath_neighbor(struct aspath *aspath)
 {
-	/*
-	 * Empty aspath is OK -- internal as route.
-	 * But what is the neighbor? For now let's return 0.
-	 * That should not break anything.
-	 */
-
+	/* Empty aspath is OK -- internal AS route. */
 	if (aspath->len == 0)
-		return (0);
-
+		return (rde_local_as());
 	return (aspath_extract(aspath->data, 0));
 }
 
@@ -910,76 +926,63 @@ aspath_prepend(struct aspath *asp, u_int
 	return (p);
 }
 
-/* we need to be able to search more than one as */
 int
-aspath_match(struct aspath *a, enum as_spec type, u_int32_t as)
+aspath_lenmatch(struct aspath *a, enum aslen_spec type, u_int aslen)
 {
 	u_int8_t	*seg;
-	int		 final;
+	u_int32_t	 as, lastas = 0;
+	u_int		 count = 0;
 	u_int16_t	 len, seg_size;
 	u_int8_t	 i, seg_type, seg_len;
 
-	if (type == AS_EMPTY) {
-		if (a->len == 0)
+	if (type == ASLEN_MAX) {
+		if (aslen < aspath_count(a->data, a->len))
 			return (1);
 		else
 			return (0);
 	}
 
-	final = 0;
+	/* type == ASLEN_SEQ */
 	seg = a->data;
 	for (len = a->len; len > 0; len -= seg_size, seg += seg_size) {
 		seg_type = seg[0];
 		seg_len = seg[1];
 		seg_size = 2 + sizeof(u_int32_t) * seg_len;
 
-		final = (len == seg_size);
-
-		/* just check the first (leftmost) AS */
-		if (type == AS_PEER) {
-			if (as == aspath_extract(seg, 0))
-				return (1);
-			else
-				return (0);
-		}
-		/* just check the final (rightmost) AS */
-		if (type == AS_SOURCE) {
-			/* not yet in the final segment */
-			if (!final)
-				continue;
-
-			if (as == aspath_extract(seg, seg_len - 1))
-				return (1);
-			else
-				return (0);
-		}
-
-		/* AS_TRANSIT or AS_ALL */
 		for (i = 0; i < seg_len; i++) {
-			if (as == aspath_extract(seg, i)) {
-				/*
-				 * the source (rightmost) AS is excluded from
-				 * AS_TRANSIT matches.
-				 */
-				if (final && i == seg_len - 1 &&
-				    type == AS_TRANSIT)
-					return (0);
-				return (1);
-			}
+			/* what should we do with AS_SET? */
+			as = aspath_extract(seg, i);
+			if (as == lastas) {
+				if (aslen < ++count)
+					return (1);
+			} else
+				count = 1;
+			lastas = as;
 		}
 	}
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
@@ -1000,7 +1003,6 @@ community_set(struct rde_aspath *asp, in
 	u_int8_t	*p = NULL;
 	unsigned int	 i, ncommunities = 0;
 	u_int8_t	 f = ATTR_OPTIONAL|ATTR_TRANSITIVE;
-	u_int8_t	 t = ATTR_COMMUNITIES;
 
 	attr = attr_optget(asp, ATTR_COMMUNITIES);
 	if (attr != NULL) {
@@ -1017,7 +1019,7 @@ community_set(struct rde_aspath *asp, in
 		p += 4;
 	}
 
-	if (ncommunities++ >= 0x3fff)
+	if (ncommunities++ >= USHRT_MAX / 4)
 		/* overflow */
 		return (0);
 
@@ -1032,11 +1034,10 @@ community_set(struct rde_aspath *asp, in
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
@@ -1049,7 +1050,7 @@ community_delete(struct rde_aspath *asp,
 	u_int8_t	*p, *n;
 	u_int16_t	 l, len = 0;
 	u_int16_t	 eas, etype;
-	u_int8_t	 f, t;
+	u_int8_t	 f;
 
 	attr = attr_optget(asp, ATTR_COMMUNITIES);
 	if (attr == NULL)
@@ -1100,10 +1101,250 @@ community_delete(struct rde_aspath *asp,
 	}
 
 	f = attr->flags;
-	t = attr->type;
 
 	attr_free(asp, attr);
-	attr_optadd(asp, f, t, n, len);
+	attr_optadd(asp, f, ATTR_COMMUNITIES, n, len);
 	free(n);
 }
 
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
+	free(n);
+}
+
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
