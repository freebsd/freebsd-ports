--- level1/dot/x86_64/zdot.S	Mon Jan  1 01:15:06 2007
+++ level1/dot/x86_64/zdot.S	Tue Feb  6 09:05:33 2007
@@ -266,12 +266,12 @@
 	FST	1 * SIZE(%rax)
 	FST	0 * SIZE(%rax)
 #elif defined(F_INTERFACE) && defined(F_INTERFACE_GFORT) && !defined(DOUBLE)
-	subq	$2 * SIZE, rsp
-	FST	1 * SIZE(rsp)
-	FST	0 * SIZE(rsp)
-	movq	0 * SIZE(rsp), %rax
-	movq	1 * SIZE(rsp), %edx
-	addq	$2 * SIZE, rsp
+	subq	$2 * SIZE, %rsp
+	FST	1 * SIZE(%rsp)
+	FST	0 * SIZE(%rsp)
+	movq	0 * SIZE(%rsp), %rax
+	movq	1 * SIZE(%rsp), %rdx
+	addq	$2 * SIZE, %rsp
 #else
 	fxch	%st(1)
 #endif
