--- hclink.c.orig	2010-07-19 21:01:56.000000000 +0200
+++ hclink.c	2012-11-05 13:16:09.731500043 +0100
@@ -49,7 +49,7 @@
 	    av[n++] = "-C";
 	for (m = 0; m < ssh_argc; m++)
 	    av[n++] = ssh_argv[m];
-	av[n++] = "-T";
+	av[n++] = "--";
 	av[n++] = hc->host;
 	av[n++] = "cpdup";
 	av[n++] = (readonly ? "-RS" : "-S");
@@ -388,7 +388,7 @@
 hcc_check_space(hctransaction_t trans, struct HCHead *head, int n, int size)
 {
     size = HCC_ALIGN(size) + n * sizeof(struct HCLeaf);
-    if (size > HC_BUFSIZE - trans->windex) {
+    if (size >= HC_BUFSIZE - trans->windex) {
 	struct HCHead *whead = (void *)trans->wbuf;
 
 	whead->cmd |= HCF_CONTINUE;
