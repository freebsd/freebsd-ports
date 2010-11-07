--- src/include/tcsd_ops.h.orig	2010-01-29 01:27:51.000000000 +0900
+++ src/include/tcsd_ops.h	2010-10-24 21:04:04.827558718 +0900
@@ -123,7 +123,7 @@
 
 struct tcsd_op {
 	char *name;
-	int op[];
+	int op[20];
 };
 
 struct tcsd_op tcsd_op_seal = {"seal", {TCSD_OP_SEAL}};
