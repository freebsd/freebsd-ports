--- libclamav/bytecode_detect.c.orig	2010-08-16 08:30:31.000000000 -0300
+++ libclamav/bytecode_detect.c	2010-08-16 08:29:48.000000000 -0300
@@ -185,6 +185,7 @@
     /* -- Detect arch -- */
     CHECK_ARCH(i386);
     else CHECK_ARCH(x86_64);
+    else if (!strcmp(TARGET_ARCH_TYPE,"amd64")) env->arch = arch_x86_64;
     else if (!strcmp(TARGET_ARCH_TYPE,"ppc")) env->arch = arch_ppc32;/* llvm will fix ppc64 */
     else CHECK_ARCH(arm);
     else CHECK_ARCH(sparc);
