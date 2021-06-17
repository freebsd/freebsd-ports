--- v8/src/base/cpu.cc.orig	2021-05-12 22:13:52 UTC
+++ v8/src/base/cpu.cc
@@ -572,6 +572,7 @@ CPU::CPU()
 
 #if V8_OS_LINUX
 
+#if V8_OS_LINUX
   CPUInfo cpu_info;
 
   // Extract implementor from the "CPU implementer" field.
@@ -605,6 +606,7 @@ CPU::CPU()
     }
     delete[] part;
   }
+#endif
 
   // Extract architecture from the "CPU Architecture" field.
   // The list is well-known, unlike the the output of
