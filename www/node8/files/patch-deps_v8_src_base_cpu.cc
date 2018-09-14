--- deps/v8/src/base/cpu.cc.orig	2018-09-10 18:46:54 UTC
+++ deps/v8/src/base/cpu.cc
@@ -607,6 +607,7 @@ CPU::CPU()
 
 #elif V8_HOST_ARCH_ARM64
 
+#if V8_OS_LINUX
   CPUInfo cpu_info;
 
   // Extract implementor from the "CPU implementer" field.
@@ -641,6 +642,8 @@ CPU::CPU()
     delete[] part;
   }
 
+#endif  // V8_OS_LINUX
+
 #elif V8_HOST_ARCH_PPC
 
 #ifndef USE_SIMULATOR
