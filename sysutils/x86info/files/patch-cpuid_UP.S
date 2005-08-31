--- cpuid_UP.S.orig	Wed Aug 24 20:15:46 2005
+++ cpuid_UP.S	Wed Aug 24 20:16:16 2005
@@ -1,24 +1,9 @@
 	.align 4
 	.text
 
-#ifdef linux
-
 .globl cpuid_UP
 	.type	cpuid_UP,@function
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
 
 #ifdef __x86_64__
 /* x86_64 calling convention: Args passed in rdi, rsi, rdx, rcx, r8, r9;
