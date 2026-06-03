--- cargo-crates/v8-147.4.0/v8/src/base/cpu.cc.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/v8-147.4.0/v8/src/base/cpu.cc
@@ -674,6 +674,7 @@ CPU::CPU()
 
 #if V8_OS_LINUX
 
+#if V8_OS_LINUX
   CPUInfo cpu_info;
 
   // Extract implementor from the "CPU implementer" field.
@@ -707,6 +708,7 @@ CPU::CPU()
     }
     delete[] part;
   }
+#endif
 
   // Extract architecture from the "CPU Architecture" field.
   // The list is well-known, unlike the the output of
