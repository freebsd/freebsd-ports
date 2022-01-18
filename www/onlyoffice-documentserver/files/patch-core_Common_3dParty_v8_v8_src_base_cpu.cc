--- core/Common/3dParty/v8/v8/src/base/cpu.cc.orig	2020-12-15 11:23:25 UTC
+++ core/Common/3dParty/v8/v8/src/base/cpu.cc
@@ -534,6 +534,7 @@ CPU::CPU()
 
 #if V8_OS_LINUX
 
+#if V8_OS_LINUX
   CPUInfo cpu_info;
 
   // Extract implementor from the "CPU implementer" field.
@@ -567,6 +568,7 @@ CPU::CPU()
     }
     delete[] part;
   }
+#endif
 
   // Extract architecture from the "CPU Architecture" field.
   // The list is well-known, unlike the the output of
