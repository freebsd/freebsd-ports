--- cargo-crates/v8-137.2.1/v8/src/base/cpu.cc.orig	2020-06-26 16:28:04 UTC
+++ cargo-crates/v8-137.2.1/v8/src/base/cpu.cc
@@ -475,6 +475,7 @@ CPU::CPU()
 
 #if V8_OS_LINUX
 
+#if V8_OS_LINUX
   CPUInfo cpu_info;
 
   // Extract implementor from the "CPU implementer" field.
@@ -508,6 +509,7 @@ CPU::CPU()
     }
     delete[] part;
   }
+#endif
 
   // Extract architecture from the "CPU Architecture" field.
   // The list is well-known, unlike the the output of
