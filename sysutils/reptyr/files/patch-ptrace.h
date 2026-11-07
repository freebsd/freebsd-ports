--- ptrace.h.orig	2026-11-07 15:40:59 UTC
+++ ptrace.h
@@ -50,6 +50,14 @@
 #ifndef PTRACE_GETREGSET
 #define PTRACE_GETREGSET  0x4204
 #endif
+
+/*
+ * FreeBSD now defines struct ptrace_child in <sys/ptrace.h>.
+ * Rename reptyr's private type to avoid a namespace collision.
+ */
+#if defined(__FreeBSD__)
+#define ptrace_child reptyr_ptrace_child
+#endif
 #ifndef PTRACE_SETREGSET
 #define PTRACE_SETREGSET  0x4205
 #endif
