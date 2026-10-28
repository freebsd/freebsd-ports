--- platform/freebsd/arch/powerpc64.h.orig	2026-10-28 12:40:19 UTC
+++ platform/freebsd/arch/powerpc64.h
@@ -41,9 +41,9 @@ static struct ptrace_personality arch_personality[1] =
 
 #define ptr(regs, off) ((unsigned long*)((void*)(regs)+(off)))
 
-static inline void arch_fixup_regs(struct ptrace_child *child, struct reg *regs) {
+static inline void arch_fixup_regs(struct ptrace_child *child) {
     /* SRR0 already points past the 4-byte sc instruction. */
-    regs->pc -= 4;
+    child->regs.pc -= 4;
 }
 
 static inline void arch_set_register(struct ptrace_child *child, unsigned long oft, unsigned long val)
