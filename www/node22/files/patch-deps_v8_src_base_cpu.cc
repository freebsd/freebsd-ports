--- deps/v8/src/base/cpu.cc.orig	2026-07-28 22:07:49 UTC
+++ deps/v8/src/base/cpu.cc
@@ -23,6 +23,10 @@
 #if V8_OS_LINUX && (V8_HOST_ARCH_PPC || V8_HOST_ARCH_PPC64)
 #include <elf.h>
 #endif
+#if V8_OS_FREEBSD && (V8_HOST_ARCH_PPC || V8_HOST_ARCH_PPC64)
+#include <machine/cpu.h>
+#include <sys/auxv.h>
+#endif
 #if V8_OS_AIX
 #include <sys/systemcfg.h>  // _system_configuration
 #ifndef POWER_8
@@ -887,6 +891,25 @@
     }
   }
 
+#elif V8_OS_FREEBSD
+  u_long hwcap = 0;
+  u_long hwcap2 = 0;
+  elf_aux_info(AT_HWCAP, &hwcap, sizeof(hwcap));
+  elf_aux_info(AT_HWCAP2, &hwcap2, sizeof(hwcap2));
+  if (hwcap2 & PPC_FEATURE2_ARCH_3_1) {
+    part_ = kPPCPower10;
+  } else if (hwcap2 & PPC_FEATURE2_ARCH_3_00) {
+    part_ = kPPCPower9;
+  } else if (hwcap2 & PPC_FEATURE2_ARCH_2_07) {
+    part_ = kPPCPower8;
+  } else if (!(hwcap & PPC_FEATURE_BOOKE)) {
+    if (hwcap & PPC_FEATURE_ARCH_2_06) {
+      part_ = kPPCPower7;
+    } else if (hwcap & PPC_FEATURE_ARCH_2_05) {
+      part_ = kPPCPower6;
+    }
+  }
+
 #elif V8_OS_AIX
   switch (_system_configuration.implementation) {
     case POWER_10:
