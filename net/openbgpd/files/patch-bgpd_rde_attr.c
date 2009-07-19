Index: bgpd/rde_attr.c
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpd/rde_attr.c,v
retrieving revision 1.1.1.1
retrieving revision 1.3
diff -u -p -r1.1.1.1 -r1.3
--- bgpd/rde_attr.c	30 Jun 2009 05:46:15 -0000	1.1.1.1
+++ bgpd/rde_attr.c	9 Jul 2009 17:22:14 -0000	1.3
@@ -1,4 +1,4 @@
-/*	$OpenBSD: rde_attr.c,v 1.76.2.1 2009/02/18 20:30:36 claudio Exp $ */
+/*	$OpenBSD: rde_attr.c,v 1.79 2009/03/19 06:52:59 claudio Exp $ */
 
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
@@ -62,6 +69,31 @@ attr_write(void *p, u_int16_t p_len, u_i
 	return (tot_len);
 }
 
+int
+attr_writebuf(struct buf *buf, u_int8_t flags, u_int8_t type, void *data,
+    u_int16_t data_len)
+{
+	u_char	hdr[4];
+
+	if (data_len > 255) {
+		flags |= ATTR_EXTLEN;
+		hdr[2] = (data_len >> 8) & 0xff;
+		hdr[3] = data_len & 0xff;
+	} else {
+		flags &= ~ATTR_EXTLEN;
+		hdr[2] = data_len & 0xff;
+	}
+
+	hdr[0] = flags;
+	hdr[1] = type;
+
+	if (buf_add(buf, hdr, flags & ATTR_EXTLEN ? 4 : 3) == -1)
+		return (-1);
+	if (buf_add(buf, data, data_len) == -1)
+		return (-1);
+	return (0);
+}
+
 /* optional attribute specific functions */
 int		 attr_diff(struct attr *, struct attr *);
 struct attr	*attr_alloc(u_int8_t, u_int8_t, const void *, u_int16_t);
@@ -588,7 +620,7 @@ aspath_merge(struct rde_aspath *a, struc
 
 	ascnt = aspath_count(attr->data, attr->len);
 	if (ascnt > a->aspath->ascnt) {
-		/* ASPATH is shorter then NEW_ASPATH no way to merge */
+		/* ASPATH is shorter then AS4_PATH no way to merge */
 		attr_free(a, attr);
 		return;
 	}
