--- ./hclink.c.orig	2010-09-25 18:01:27.989863475 -0400
+++ ./hclink.c	2010-09-25 18:01:46.138176079 -0400
@@ -388,7 +388,7 @@
 hcc_check_space(hctransaction_t trans, struct HCHead *head, int n, int size)
 {
     size = HCC_ALIGN(size) + n * sizeof(struct HCLeaf);
-    if (size > HC_BUFSIZE - trans->windex) {
+    if (size >= HC_BUFSIZE - trans->windex) {
 	struct HCHead *whead = (void *)trans->wbuf;
 
 	whead->cmd |= HCF_CONTINUE;
