--- src/zm_signal.cpp.orig	2026-02-16 23:32:05 UTC
+++ src/zm_signal.cpp
@@ -130,9 +130,17 @@ RETSIGTYPE zm_die_handler(int signal)
     ip = (void *)(uc->uc_mcontext.gregs[REG_EIP]);
 #endif
 #elif defined(__aarch64__)
+#if defined(__FreeBSD_kernel__) || defined(__FreeBSD__)
+    ip = (void *)(uc->uc_mcontext.mc_gpregs.gp_elr);
+#else
     ip = (void *)(uc->uc_mcontext.pc);
+#endif
 #elif defined(__arm__)
+#if defined(__FreeBSD_kernel__) || defined(__FreeBSD__)
+    ip = (void *)(uc->uc_mcontext.__gregs[_REG_PC]);
+#else
     ip = (void *)(uc->uc_mcontext.arm_pc);
+#endif
 #endif
 
     // Print the fault address and instruction pointer
