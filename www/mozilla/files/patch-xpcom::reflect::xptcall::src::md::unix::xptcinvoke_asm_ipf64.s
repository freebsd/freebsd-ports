--- xpcom/reflect/xptcall/src/md/unix/xptcinvoke_asm_ipf64.s.orig	Sun Jul 20 00:05:32 2003
+++ xpcom/reflect/xptcall/src/md/unix/xptcinvoke_asm_ipf64.s	Sun Jul 20 00:06:37 2003
@@ -8,6 +8,7 @@
 // Section has executable code
         .section .text, "ax","progbits"
 // procedure named 'XPTC_InvokeByIndex'
+	.global	XPTC_InvokeByIndex
         .proc   XPTC_InvokeByIndex
 // manual bundling
         .explicit
@@ -24,7 +25,7 @@
 
 // XPTC_InvokeByIndex(nsISupports* that, PRUint32 methodIndex,
 //   PRUint32 paramCount, nsXPTCVariant* params);
-XPTC_InvokeByIndex::
+XPTC_InvokeByIndex:
         .prologue
         .save ar.pfs, r37
 // allocate 4 input args, 6 local args, and 8 output args
