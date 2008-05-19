--- pftop.c.orig	2007-11-07 01:36:46.000000000 -0500
+++ pftop.c	2008-05-16 15:57:12.000000000 -0400
@@ -1486,7 +1486,13 @@
 	print_fld_size(FLD_BYTES, pr->bytes);
 #endif
 	print_fld_uint(FLD_RULE, pr->nr);
-	print_fld_str(FLD_DIR, pr->direction == PF_OUT ? "Out" : "In");
+	if (pr->direction == PF_IN)
+		print_fld_str(FLD_DIR, "In");
+	else if (pr->direction == PF_OUT)
+		print_fld_str(FLD_DIR, "Out");
+	else
+		print_fld_str(FLD_DIR, "Any");
+
 	if (pr->quick)
 		print_fld_str(FLD_QUICK, "Quick");
 
@@ -1570,10 +1576,10 @@
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
@@ -1765,7 +1771,12 @@
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
