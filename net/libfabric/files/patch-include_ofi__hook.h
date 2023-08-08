--- include/ofi_hook.h.orig	2022-04-30 21:46:31 UTC
+++ include/ofi_hook.h
@@ -163,7 +163,7 @@ struct hook_domain {
 	struct fid_domain *hdomain;
 	struct hook_fabric *fabric;
 	struct ofi_ops_flow_ctrl *base_ops_flow_ctrl;
-	ssize_t (*base_credit_handler)(struct fid_ep *ep_fid, size_t credits);
+	ssize_t (*base_credit_handler)(struct fid_ep *ep_fid, uint64_t credits);
 };
 
 int hook_domain_init(struct fid_fabric *fabric, struct fi_info *info,
