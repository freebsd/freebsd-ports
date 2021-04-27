--- v8/src/base/cpu.cc.orig	2021-04-14 18:43:14 UTC
+++ v8/src/base/cpu.cc
@@ -545,6 +545,7 @@ CPU::CPU()
 
 #if V8_OS_LINUX
 
+#if V8_OS_LINUX
   CPUInfo cpu_info;
 
   // Extract implementor from the "CPU implementer" field.
@@ -578,6 +579,7 @@ CPU::CPU()
     }
     delete[] part;
   }
+#endif
 
   // Extract architecture from the "CPU Architecture" field.
   // The list is well-known, unlike the the output of
