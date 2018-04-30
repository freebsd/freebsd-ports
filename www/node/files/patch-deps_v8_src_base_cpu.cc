--- deps/v8/src/base/cpu.cc.orig	2018-04-23 19:19:12 UTC
+++ deps/v8/src/base/cpu.cc
@@ -424,6 +424,7 @@ CPU::CPU()
 
 #if V8_OS_LINUX
 
+#if V8_OS_LINUX
   CPUInfo cpu_info;
 
   // Extract implementor from the "CPU implementer" field.
@@ -457,6 +458,8 @@ CPU::CPU()
     }
     delete[] part;
   }
+
+#endif  // V8_OS_LINUX
 
   // Extract architecture from the "CPU Architecture" field.
   // The list is well-known, unlike the the output of
