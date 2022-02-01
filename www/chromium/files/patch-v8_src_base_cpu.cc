--- v8/src/base/cpu.cc.orig	2021-12-31 01:01:02 UTC
+++ v8/src/base/cpu.cc
@@ -575,6 +575,7 @@ CPU::CPU()
 
 #if V8_OS_LINUX
 
+#if V8_OS_LINUX
   CPUInfo cpu_info;
 
   // Extract implementor from the "CPU implementer" field.
@@ -608,6 +609,7 @@ CPU::CPU()
     }
     delete[] part;
   }
+#endif
 
   // Extract architecture from the "CPU Architecture" field.
   // The list is well-known, unlike the the output of
