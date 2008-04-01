--- pftop.c.orig	2007-11-07 07:36:46.000000000 +0100
+++ pftop.c	2008-04-01 17:03:25.847268996 +0200
@@ -1570,10 +1570,10 @@
 #ifdef HAVE_RULE_UGID
 	if (pr->uid.op)
 		tb_print_ugid(pr->uid.op, pr->uid.uid[0], pr->uid.uid[1],
-		        "user", UID_MAX);
+		        "user", UINT_MAX);
 	if (pr->gid.op)
 		tb_print_ugid(pr->gid.op, pr->gid.gid[0], pr->gid.gid[1],
-		        "group", GID_MAX);
+		        "group", UINT_MAX);
 #endif
 
 	if (pr->flags || pr->flagset) {
@@ -1765,7 +1765,12 @@
 				  strerror(errno));
 			return (-1);
 		}
+#ifdef PFALTQ_FLAG_IF_REMOVED
+		if (pa.altq.qid > 0 &&
+		    !(pa.altq.local_flags & PFALTQ_FLAG_IF_REMOVED)) {
+#else
 		if (pa.altq.qid > 0) {
+#endif
 			pq.nr = nr;
 			pq.ticket = pa.ticket;
 			pq.buf = &qstats;
