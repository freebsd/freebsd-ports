--- prov/rxm/src/rxm_domain.c.orig	2022-04-30 21:46:32 UTC
+++ prov/rxm/src/rxm_domain.c
@@ -567,7 +621,7 @@ static struct fi_ops_mr rxm_domain_mr_thru_ops = {
 	.regattr = rxm_mr_regattr_thru,
 };
 
-static ssize_t rxm_send_credits(struct fid_ep *ep, size_t credits)
+static ssize_t rxm_send_credits(struct fid_ep *ep, uint64_t credits)
 {
 	struct rxm_conn *rxm_conn = ep->fid.context;
 	struct rxm_ep *rxm_ep = rxm_conn->ep;
@@ -620,11 +674,11 @@ defer:
 	return FI_SUCCESS;
 }
 
-static void rxm_no_add_credits(struct fid_ep *ep_fid, size_t credits)
+static void rxm_no_add_credits(struct fid_ep *ep_fid, uint64_t credits)
 { }
 
 static void rxm_no_credit_handler(struct fid_domain *domain_fid,
-		ssize_t (*credit_handler)(struct fid_ep *ep, size_t credits))
+		ssize_t (*credit_handler)(struct fid_ep *ep, uint64_t credits))
 { }
 
 static int rxm_no_enable_flow_ctrl(struct fid_ep *ep_fid, uint64_t threshold)
