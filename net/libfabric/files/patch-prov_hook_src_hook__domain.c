--- prov/hook/src/hook_domain.c.orig	2022-04-30 21:46:31 UTC
+++ prov/hook/src/hook_domain.c
@@ -102,7 +102,7 @@ static struct fi_ops_mr hook_mr_ops = {
 	.regattr = hook_mr_regattr,
 };
 
-static ssize_t hook_credit_handler(struct fid_ep *ep_fid, size_t credits)
+static ssize_t hook_credit_handler(struct fid_ep *ep_fid, uint64_t credits)
 {
 	/*
 	 * called from the base provider, ep_fid is the base ep, and
@@ -114,7 +114,7 @@ static void hook_set_send_handler(struct fid_domain *d
 }
 
 static void hook_set_send_handler(struct fid_domain *domain_fid,
-		ssize_t (*credit_handler)(struct fid_ep *ep, size_t credits))
+		ssize_t (*credit_handler)(struct fid_ep *ep, uint64_t credits))
 {
 	struct hook_domain *domain = container_of(domain_fid,
 						  struct hook_domain, domain);
@@ -131,7 +131,7 @@ static int hook_enable_ep_flow_ctrl(struct fid_ep *ep_
 	return ep->domain->base_ops_flow_ctrl->enable(ep->hep, threshold);
 }
 
-static void hook_add_credits(struct fid_ep *ep_fid, size_t credits)
+static void hook_add_credits(struct fid_ep *ep_fid, uint64_t credits)
 {
 	struct hook_ep *ep = container_of(ep_fid, struct hook_ep, ep);
 
