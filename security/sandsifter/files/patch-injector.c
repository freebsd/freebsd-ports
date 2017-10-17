--- injector.c.orig	2017-07-27 19:17:30 UTC
+++ injector.c
@@ -77,10 +77,24 @@ cs_insn *capstone_insn;
 
 /* 32 vs 64 */
 
-#if __x86_64__
-	#define IP REG_RIP 
+#ifdef __linux__
+#	define PAGE_SIZE 4096
+#	define EFL gregs[REG_EFL]
+#	if __x86_64__
+#		define IP gregs[REG_RIP]
+#	else
+#		define IP gregs[REG_EIP]
+#	endif
 #else
-	#define IP REG_EIP 
+#	include <pthread_np.h>
+	typedef cpuset_t cpu_set_t;
+#	if __x86_64__
+#		define IP mc_rip
+#		define EFL mc_rflags
+#	else
+#		define IP mc_eip
+#		define EFL mc_eflags
+#	endif
 #endif
 
 /* leave state as 0 */
@@ -155,7 +169,6 @@ state_t inject_state={
 /* x86/64 */
 
 #define UD2_SIZE  2
-#define PAGE_SIZE 4096
 #define TF        0x100
 
 /* injection */
@@ -293,6 +306,10 @@ ignore_op_t opcode_blacklist[MAX_BLACKLIST]={
 	{ "\xcd\x80", "int 0x80" },
 	/* as will syscall */
 	{ "\x0f\x05", "syscall" },
+	/* int 92 on FreeBSD triggers DTrace, which will trigger SIGSYS */
+	{ "\xcd\x92", "int 0x92" },
+	/* int 93 on FreeBSD is used by Xen */
+	{ "\xcd\x93", "int 0x93" },
 	/* ud2 is an undefined opcode, and messes up a length differential search
 	 * b/c of the fault it throws */
 	{ "\x0f\xb9", "ud2" },
@@ -850,7 +867,7 @@ void inject(int insn_size)
 void state_handler(int signum, siginfo_t* si, void* p)
 {
 	fault_context=((ucontext_t*)p)->uc_mcontext;
-	((ucontext_t*)p)->uc_mcontext.gregs[IP]+=UD2_SIZE;
+	((ucontext_t*)p)->uc_mcontext.IP+=UD2_SIZE;
 }
 
 void fault_handler(int signum, siginfo_t* si, void* p)
@@ -863,7 +880,7 @@ void fault_handler(int signum, siginfo_t* si, void* p)
 
 	/* make an initial estimate on the instruction length from the fault address */
 	insn_length=
-		(uintptr_t)uc->uc_mcontext.gregs[IP]-(uintptr_t)packet-preamble_length;
+		(uintptr_t)uc->uc_mcontext.IP-(uintptr_t)packet-preamble_length;
 
 	if (insn_length<0) {
 		insn_length=JMP_LENGTH;
@@ -880,9 +897,13 @@ void fault_handler(int signum, siginfo_t* si, void* p)
 		(signum==SIGSEGV||signum==SIGBUS)?(uint32_t)(uintptr_t)si->si_addr:(uint32_t)-1
 	};
 
+#ifdef __linux__
 	memcpy(uc->uc_mcontext.gregs, fault_context.gregs, sizeof(fault_context.gregs));
-	uc->uc_mcontext.gregs[IP]=(uintptr_t)&resume;
-	uc->uc_mcontext.gregs[REG_EFL]&=~TF;
+#else
+	memcpy(&uc->uc_mcontext, &fault_context, sizeof(fault_context));
+#endif
+	uc->uc_mcontext.IP=(uintptr_t)&resume;
+	uc->uc_mcontext.EFL&=~TF;
 }
 
 void configure_sig_handler(void (*handler)(int, siginfo_t*, void*))
@@ -1341,7 +1362,13 @@ void pin_core(void)
 		cpu_set_t mask;
 		CPU_ZERO(&mask);
 		CPU_SET(config.core,&mask);
-		if (sched_setaffinity(0, sizeof(mask), &mask)) {
+#ifdef __linux__
+		if (sched_setaffinity(0, sizeof(mask), &mask))
+#else
+		if (cpuset_setaffinity(CPU_LEVEL_WHICH, CPU_WHICH_PID,
+		    -1, sizeof(mask), &mask))
+#endif
+		{
 			printf("error: failed to set cpu\n");
 			exit(1);
 		}
@@ -1439,7 +1466,7 @@ int main(int argc, char** argv)
 		null_p=mmap(0, PAGE_SIZE, PROT_READ|PROT_WRITE,
 			MAP_FIXED|MAP_PRIVATE|MAP_ANONYMOUS, -1, 0);
 		if (null_p==MAP_FAILED) {
-			printf("null access requires running as root\n");
+			printf("null access requires running as root, %i\n", errno);
 			exit(1);
 		}
 	}
