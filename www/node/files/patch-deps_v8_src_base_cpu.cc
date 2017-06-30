--- deps/v8/src/base/cpu.cc.orig	2017-06-19 14:24:53.928317000 +0000
+++ deps/v8/src/base/cpu.cc	2017-06-19 14:24:57.294664000 +0000
@@ -601,6 +601,7 @@
 
 #elif V8_HOST_ARCH_ARM64
 
+#if V8_OS_LINUX
   CPUInfo cpu_info;
 
   // Extract implementor from the "CPU implementer" field.
@@ -634,6 +635,8 @@
     }
     delete[] part;
   }
+
+#endif  // V8_OS_LINUX
 
 #elif V8_HOST_ARCH_PPC
 
