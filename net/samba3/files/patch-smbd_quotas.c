--- smbd/quotas.c.orig	2008-07-15 05:19:02.000000000 +0200
+++ smbd/quotas.c	2008-07-15 05:21:24.000000000 +0200
@@ -546,7 +546,7 @@
 	*bsize = gqr.getquota_rslt_u.gqr_rquota.rq_bsize;
 	*dsize = D.dqb_bsoftlimit;
 
-	if (D.dqb_curblocks == D.dqb_curblocks == 1)
+	if (D.dqb_curblocks == 1)
 		*bsize = 512;
 
 	if (D.dqb_curblocks > D.dqb_bsoftlimit) {
@@ -1091,7 +1091,7 @@
 	*bsize = gqr.getquota_rslt_u.gqr_rquota.rq_bsize;
 	*dsize = D.dqb_bsoftlimit;
 
-	if (D.dqb_curblocks == D.dqb_curblocks == 1)
+	if (D.dqb_curblocks == 1)
 		*bsize = DEV_BSIZE;
 
 	if (D.dqb_curblocks > D.dqb_bsoftlimit) {
