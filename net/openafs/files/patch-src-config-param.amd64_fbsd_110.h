--- src/config/param.amd64_fbsd_110.h.orig	2014-10-09 18:21:13.000000000 +0900
+++ src/config/param.amd64_fbsd_110.h	2014-11-08 12:19:21.000000000 +0900
@@ -144,6 +144,11 @@
 #endif /* ! ASSEMBLER & ! __LANGUAGE_ASSEMBLY__ */
 #endif /* _KERNEL */
 
+/* r273707 added a flags argument to syscall_register() */
+#if __FreeBSD_version >= 1100041
+#define FBSD_SYSCALL_REGISTER_FOUR_ARGS
+#endif
+
 #else /* !defined(UKERNEL) */
 
 /* This section for user space compiles only */
