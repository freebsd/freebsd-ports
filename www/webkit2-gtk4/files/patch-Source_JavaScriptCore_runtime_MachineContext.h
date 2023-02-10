Index: Source/JavaScriptCore/runtime/MachineContext.h
--- Source/JavaScriptCore/runtime/MachineContext.h.orig
+++ Source/JavaScriptCore/runtime/MachineContext.h
@@ -193,6 +193,22 @@ static inline void*& stackPointerImpl(mcontext_t& mach
 #error Unknown Architecture
 #endif
 
+#elif OS(OPENBSD)
+
+#if CPU(X86)
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.sc_esp);
+#elif CPU(X86_64)
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.sc_rsp);
+#elif CPU(ARM) 
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.__gregs[_REG_SP]);
+#elif CPU(ARM64)
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.sc_sp);
+#elif CPU(MIPS)
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.mc_regs[29]);
+#else
+#error Unknown Architecture
+#endif
+
 #elif OS(FUCHSIA) || OS(LINUX)
 
 #if CPU(X86)
@@ -338,6 +354,22 @@ static inline void*& framePointerImpl(mcontext_t& mach
 #error Unknown Architecture
 #endif
 
+#elif OS(OPENBSD)
+
+#if CPU(X86)
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.sc_ebp);
+#elif CPU(X86_64)
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.sc_rbp);
+#elif CPU(ARM) 
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.__gregs[_REG_FP]);
+#elif CPU(ARM64)
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.sc_x[29]);
+#elif CPU(MIPS)
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.mc_regs[30]);
+#else
+#error Unknown Architecture
+#endif
+
 #elif OS(FUCHSIA) || OS(LINUX)
 
 // The following sequence depends on glibc's sys/ucontext.h.
@@ -496,6 +528,22 @@ static inline void*& instructionPointerImpl(mcontext_t
 #error Unknown Architecture
 #endif
 
+#elif OS(OPENBSD)
+
+#if CPU(X86)
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.sc_eip);
+#elif CPU(X86_64)
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.sc_rip);
+#elif CPU(ARM) 
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.__gregs[_REG_PC]);
+#elif CPU(ARM64)
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.sc_elr);
+#elif CPU(MIPS)
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.mc_pc);
+#else
+#error Unknown Architecture
+#endif
+
 #elif OS(FUCHSIA) || OS(LINUX)
 
 // The following sequence depends on glibc's sys/ucontext.h.
@@ -652,6 +700,22 @@ inline void*& argumentPointer<1>(mcontext_t& machineCo
 #error Unknown Architecture
 #endif
 
+#elif OS(OPENBSD)
+
+#if CPU(X86)
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.sc_edx);
+#elif CPU(X86_64)
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.sc_rsi);
+#elif CPU(ARM) 
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.__gregs[_REG_R1]);
+#elif CPU(ARM64)
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.sc_x[1]);
+#elif CPU(MIPS)
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.mc_regs[5]);
+#else
+#error Unknown Architecture
+#endif
+
 #elif OS(FUCHSIA) || OS(LINUX)
 
 // The following sequence depends on glibc's sys/ucontext.h.
@@ -765,6 +829,22 @@ inline void*& llintInstructionPointer(mcontext_t& mach
     return reinterpret_cast<void*&>((uintptr_t&) machineContext.__gregs[_REG_R8]);
 #elif CPU(ARM64)
     return reinterpret_cast<void*&>((uintptr_t&) machineContext.mc_gpregs.gp_x[4]);
+#elif CPU(MIPS)
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.mc_regs[12]);
+#else
+#error Unknown Architecture
+#endif
+
+#elif OS(OPENBSD)
+
+#if CPU(X86)
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.sc_esi);
+#elif CPU(X86_64)
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.sc_r8);
+#elif CPU(ARM) 
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.__gregs[_REG_R8]);
+#elif CPU(ARM64)
+    return reinterpret_cast<void*&>((uintptr_t&) machineContext.sc_x[4]);
 #elif CPU(MIPS)
     return reinterpret_cast<void*&>((uintptr_t&) machineContext.mc_regs[12]);
 #else
