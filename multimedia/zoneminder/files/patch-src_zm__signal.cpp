--- src/zm_signal.cpp.orig	2016-06-01 00:41:17 UTC
+++ src/zm_signal.cpp
@@ -63,17 +63,9 @@ RETSIGTYPE zm_die_handler(int signal)
 		ucontext_t *uc = (ucontext_t *) context;
 		cr2 = info->si_addr;
     #if defined(__x86_64__)
-	    #ifdef __FreeBSD_kernel__
 		ip = (void *)(uc->uc_mcontext.mc_rip);
-	    #else
-		ip = (void *)(uc->uc_mcontext.gregs[REG_RIP]);
-	    #endif
     #else
-	    #ifdef __FreeBSD_kernel__
 		ip = (void *)(uc->uc_mcontext.mc_eip);
-	    #else
-		ip = (void *)(uc->uc_mcontext.gregs[REG_EIP]);
-	    #endif
     #endif				// defined(__x86_64__)
 
 		// Print the signal address and instruction pointer if available
