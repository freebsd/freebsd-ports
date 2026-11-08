--- deps/v8/src/base/cpu.cc.orig	2026-09-08 00:10:00 UTC
+++ deps/v8/src/base/cpu.cc
@@ -23,6 +23,10 @@
 #if V8_OS_LINUX && V8_HOST_ARCH_PPC64
 #include <elf.h>
 #endif
+#if V8_OS_FREEBSD && V8_HOST_ARCH_PPC64
+#include <machine/cpu.h>
+#include <sys/auxv.h>
+#endif
 #if V8_OS_AIX
 #include <sys/systemcfg.h>  // _system_configuration
 #ifndef POWER_8
@@ -943,6 +947,15 @@
     }
   }
 
+#elif V8_OS_FREEBSD
+  u_long hwcap2 = 0;
+  elf_aux_info(AT_HWCAP2, &hwcap2, sizeof(hwcap2));
+  if (hwcap2 & PPC_FEATURE2_ARCH_3_1) {
+    part_ = kPPCPower10;
+  } else if (hwcap2 & PPC_FEATURE2_ARCH_3_00) {
+    part_ = kPPCPower9;
+  }
+
 #elif V8_OS_AIX
   switch (_system_configuration.implementation) {
     case POWER_10:
