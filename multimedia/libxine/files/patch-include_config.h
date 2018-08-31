$OpenBSD: patch-include_config_h,v 1.1 2018/02/16 14:27:53 sthen Exp $

Index: include/config.h
--- include/config.h.orig
+++ include/config.h
@@ -24,9 +24,11 @@
 /* Ugly build time sanity guard.
  * ./configure might mistake X32 mode as plain 64bit,
  * but compiler itself sets __ILP32__ when in x32.
+ * Even worse: clang sets this in 32 mode as well,
+ * so also test __i386__ here.
  */
 #ifdef ARCH_X86
-#  if defined(__ILP32__) && !defined(ARCH_X86_X32)
+#  if defined(__ILP32__) && !defined(__i386) && !defined(__i386__) && !defined(ARCH_X86_X32)
 #    ifdef ARCH_WARN
 #        warning "configure did not detect ARCH_X86_X32!"
 #    endif
