--- mtrace.c.orig	2011-10-23 10:03:36.000000000 +0200
+++ mtrace.c	2014-12-20 20:31:14.000000000 +0100
@@ -903,6 +903,12 @@ void stat_line(struct tr_resp *r, struct
     }
 }
 
+static uint32_t
+udiff(uint32_t u, uint32_t v)
+{
+	return (u >= v ? u - v : v - u);
+}
+
 /*
  * A fixup to check if any pktcnt has been reset, and to fix the
  * byteorder bugs in mrouted 3.6 on little-endian machines.
@@ -920,7 +926,7 @@ void fixup_stats(struct resp_buf *base, 
     /* Check for byte-swappers */
     while (--rno >= 0) {
 	--n; --p; --b; --s;
-	if (*s || abs(ntohl(n->tr_vifout) - ntohl(p->tr_vifout)) > 100000) {
+	if (*s || udiff(ntohl(n->tr_vifout), ntohl(p->tr_vifout)) > 100000) {
 	    /* This host sends byteswapped reports; swap 'em */
 	    if (!*s) {
 		*s = 1;
