--- prov/verbs/src/verbs_ep.c.orig	2022-05-10 03:27:55 UTC
+++ prov/verbs/src/verbs_ep.c
@@ -38,7 +38,7 @@ static struct fi_ops_msg vrb_srq_msg_ops;
 static struct fi_ops_msg vrb_srq_msg_ops;
 
 
-void vrb_add_credits(struct fid_ep *ep_fid, size_t credits)
+void vrb_add_credits(struct fid_ep *ep_fid, uint64_t credits)
 {
 	struct vrb_ep *ep;
 	struct util_cq *cq;
