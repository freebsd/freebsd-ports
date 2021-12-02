--- platform/freebsd/arch/x86_common.h.orig	2020-09-29 14:29:59.000000000 -0700
+++ platform/freebsd/arch/x86_common.h	2021-12-01 19:58:27.954536000 -0800
@@ -42,21 +42,19 @@
 }
 
 static inline unsigned long arch_get_register(struct ptrace_child *child, unsigned long oft){
-	int ret;
 	struct reg regs;
 
-	ret = ptrace_command(child, PT_GETREGS, &regs);
+	(void) ptrace_command(child, PT_GETREGS, &regs);
 
 	return *ptr(&regs,oft);
 }
 
 static inline void arch_set_register(struct ptrace_child *child, unsigned long oft, unsigned long val){
-	int ret;
 	struct reg regs;
 
-	ret = ptrace_command(child, PT_GETREGS, &regs);
+	(void) ptrace_command(child, PT_GETREGS, &regs);
 	*ptr(&regs,oft)=val;
-	ret = ptrace_command(child, PT_SETREGS, &regs);
+	(void) ptrace_command(child, PT_SETREGS, &regs);
 }
 
 static inline int arch_save_syscall(struct ptrace_child *child) {
