--- deps/v8/src/base/cpu.cc.orig	2017-08-09 18:48:10 UTC
+++ deps/v8/src/base/cpu.cc
@@ -607,6 +607,7 @@ CPU::CPU()
 
 #elif V8_HOST_ARCH_ARM64
 
+#if V8_OS_LINUX
   CPUInfo cpu_info;
 
   // Extract implementor from the "CPU implementer" field.
@@ -640,6 +641,8 @@ CPU::CPU()
     }
     delete[] part;
   }
+
+#endif  // V8_OS_LINUX
 
 #elif V8_HOST_ARCH_PPC
 
