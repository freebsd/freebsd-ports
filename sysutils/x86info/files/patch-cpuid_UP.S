--- cpuid_UP.S.orig	Tue Nov 26 20:20:07 2002
+++ cpuid_UP.S	Sun Aug 24 16:12:12 2003
@@ -1,25 +1,8 @@
 	.align 4
 	.text
 
-#ifdef linux
-
 .globl cpuid_UP
-	.type	cpuid_UP,@function
 cpuid_UP:
-
-#else /* BSD or WIN32 */
-
-.globl _cpuid_UP
-
-#ifdef __WIN32__
-	.def	_cpuid_UP;  .scl    2;      .type   32;     .endef
-#else /* BSD */
-	.type	_cpuid_UP,@function
-#endif /* __WIN32__ */
-
-_cpuid_UP:
-#endif /* linux */
-
 	pushl %ebp
 	movl %esp,%ebp
 	pushl %edi
