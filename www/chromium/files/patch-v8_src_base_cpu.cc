--- v8/src/base/cpu.cc.orig	2020-05-13 18:41:59 UTC
+++ v8/src/base/cpu.cc
@@ -427,6 +427,7 @@ CPU::CPU()
 
 #if V8_OS_LINUX
 
+#if V8_OS_LINUX
   CPUInfo cpu_info;
 
   // Extract implementor from the "CPU implementer" field.
@@ -460,6 +461,7 @@ CPU::CPU()
     }
     delete[] part;
   }
+#endif
 
   // Extract architecture from the "CPU Architecture" field.
   // The list is well-known, unlike the the output of
