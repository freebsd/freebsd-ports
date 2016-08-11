--- src/include/tcsd_ops.h.orig	2016-06-20 15:21:26 UTC
+++ src/include/tcsd_ops.h
@@ -123,7 +123,7 @@
 
 struct tcsd_op {
 	char *name;
-	int op[];
+	int op[20];
 };
 
 struct tcsd_op tcsd_op_seal = {"seal", {TCSD_OP_SEAL}};
