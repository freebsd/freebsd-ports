--- prov/verbs/src/verbs_domain.c.orig	2022-04-30 21:46:32 UTC
+++ prov/verbs/src/verbs_domain.c
@@ -36,11 +36,11 @@
 #include "ofi_iov.h"
 
 #include "fi_verbs.h"
-#include <malloc.h>
+#include <stdlib.h>
 
 
 static void vrb_set_credit_handler(struct fid_domain *domain_fid,
-		ssize_t (*credit_handler)(struct fid_ep *ep, size_t credits))
+		ssize_t (*credit_handler)(struct fid_ep *ep, uint64_t credits))
 {
 	struct vrb_domain *domain;
 
