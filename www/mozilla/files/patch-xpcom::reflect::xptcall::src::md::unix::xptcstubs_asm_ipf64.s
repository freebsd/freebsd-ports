--- xpcom/reflect/xptcall/src/md/unix/xptcstubs_asm_ipf64.s.orig	Sun Jul 20 00:02:02 2003
+++ xpcom/reflect/xptcall/src/md/unix/xptcstubs_asm_ipf64.s	Sun Jul 20 00:02:40 2003
@@ -6,6 +6,7 @@
 // Section has executable code
         .section .text, "ax","progbits"
 // procedure named 'SharedStub'
+	.global SharedStub
         .proc   SharedStub
 // manual bundling
         .explicit
@@ -14,7 +15,7 @@
 //      .exclass  PrepareAndDispatch, @fullyvisible
         .type   PrepareAndDispatch,@function
 
-SharedStub::
+SharedStub:
 // 9 arguments, first 8 are the input arguments of previous
 // function call.  The last one is methodIndex, and is passed in memory
         .prologue
