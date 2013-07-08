--- src/pmvarrun.c.orig	2012-12-03 17:30:58.000000000 +0100
+++ src/pmvarrun.c	2012-12-03 17:31:19.000000000 +0100
@@ -299,7 +299,7 @@
 	int ret;
 
 	w4rn("creating " VAR_RUN_PMT);
-	if (HX_mkdir(VAR_RUN_PMT) < 0) {
+	if (HX_mkdir(VAR_RUN_PMT, S_IRWXU | S_IRXG | S_IRXO) < 0) {
 		ret = -errno;
 		l0g("unable to create " VAR_RUN_PMT ": %s\n", strerror(errno));
 		return ret;
