--- cpuid_UP.S.orig	Tue Dec 11 11:01:41 2001
+++ cpuid_UP.S	Tue Dec 18 13:42:43 2001
@@ -1,21 +1,14 @@
 	.align 4
 	.text
 
-#ifdef linux
 
+#ifdef __WIN32__
+.globl _cpuid_UP
+	.def	_cpuid_UP;  .scl    2;      .type   32;     .endef
+#else	/* a sane system */
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
 
 _cpuid_UP:
 #endif /* linux */
