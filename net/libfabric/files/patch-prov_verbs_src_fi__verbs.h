--- prov/verbs/src/fi_verbs.h.orig	2022-05-13 15:08:17 UTC
+++ prov/verbs/src/fi_verbs.h
@@ -943,7 +943,7 @@ ssize_t vrb_send_iov(struct vrb_ep *ep, struct ibv_sen
 		     const struct iovec *iov, void **desc, int count,
 		     uint64_t flags);
 
-void vrb_add_credits(struct fid_ep *ep, size_t credits);
+void vrb_add_credits(struct fid_ep *ep, uint64_t credits);
 
 int vrb_get_rai_id(const char *node, const char *service, uint64_t flags,
 		      const struct fi_info *hints, struct rdma_addrinfo **rai,
