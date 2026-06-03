--- third_party/libunwind/src/src/DwarfInstructions.hpp.orig	2026-02-15 10:01:45 UTC
+++ third_party/libunwind/src/src/DwarfInstructions.hpp
@@ -396,6 +396,23 @@ int DwarfInstructions<A, R>::stepWithDwarf(
       if (R::getArch() == REGISTERS_PPC64 && returnAddress != 0) {
         pint_t sp = newRegisters.getRegister(UNW_REG_SP);
         pint_t r2 = 0;
+#if defined(_LIBUNWIND_IS_NATIVE_ONLY) && defined(__OpenBSD__)
+        // Can't addressSpace.get32(returnAddress), because it might be
+        // in execute-only memory.  If returning to a different shared
+        // object, then restore r2.  This assumes one TOC per object.
+        // ELFv2 allows more than one (3.3 TOC, Modules Containing
+        // Multiple TOCs), but we have no way to detect that.
+        void *IPObject = NULL;
+        void *RAObject = NULL;
+        Dl_info info;
+        if (dladdr((void *)registers.getIP(), &info))
+          IPObject = info.dli_fbase;
+        if (dladdr((void *)returnAddress, &info))
+          RAObject = info.dli_fbase;
+        // Assume ELFv2.
+        if (IPObject != RAObject)
+          r2 = addressSpace.get64(sp + PPC64_ELFV2_R2_OFFSET);
+#else
         switch (addressSpace.get32(returnAddress)) {
         case PPC64_ELFV1_R2_LOAD_INST_ENCODING:
           r2 = addressSpace.get64(sp + PPC64_ELFV1_R2_OFFSET);
@@ -404,6 +421,7 @@ int DwarfInstructions<A, R>::stepWithDwarf(
           r2 = addressSpace.get64(sp + PPC64_ELFV2_R2_OFFSET);
           break;
         }
+#endif
         if (r2)
           newRegisters.setRegister(UNW_PPC64_R2, r2);
       }
