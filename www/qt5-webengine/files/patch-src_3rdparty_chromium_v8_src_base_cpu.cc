--- src/3rdparty/chromium/v8/src/base/cpu.cc.orig	2018-03-20 07:26:22 UTC
+++ src/3rdparty/chromium/v8/src/base/cpu.cc
@@ -600,7 +600,7 @@ CPU::CPU()
 #endif
 
 #elif V8_HOST_ARCH_ARM64
-
+#if V8_OS_LINUX
   CPUInfo cpu_info;
 
   // Extract implementor from the "CPU implementer" field.
@@ -634,6 +634,7 @@ CPU::CPU()
     }
     delete[] part;
   }
+#endif // V8_OS_LINUX
 
 #elif V8_HOST_ARCH_PPC
 
