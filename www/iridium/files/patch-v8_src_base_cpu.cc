--- v8/src/base/cpu.cc.orig	2017-09-11 03:04:32.333164000 +0200
+++ v8/src/base/cpu.cc	2017-09-11 03:05:48.364215000 +0200
@@ -607,6 +607,7 @@
 
 #elif V8_HOST_ARCH_ARM64
 
+#if V8_OS_LINUX
   CPUInfo cpu_info;
 
   // Extract implementor from the "CPU implementer" field.
@@ -640,6 +641,7 @@
     }
     delete[] part;
   }
+#endif
 
 #elif V8_HOST_ARCH_PPC
 
