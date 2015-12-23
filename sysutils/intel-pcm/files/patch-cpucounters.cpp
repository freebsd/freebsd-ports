--- cpucounters.cpp.orig	2015-11-17 01:01:38.000000000 -0700
+++ cpucounters.cpp	2015-12-14 14:46:09.000000000 -0700
@@ -1365,7 +1365,13 @@
         cpu_model = ATOM;
     }
     if (cpu_model == HASWELL_ULT || cpu_model == HASWELL_2) cpu_model = HASWELL;
-    if (cpu_model == BROADWELL_XEON_E3) cpu_model = BROADWELL;
+
+    if ((cpu_model == BROADWELL_XEON_E3) ||
+	(cpu_model == BROADWELL_XEON_E5) ||
+	(cpu_model == BROADWELL_XEON_E7)) {
+	cpu_model = BROADWELL;
+    }
+
     if (cpu_model == SKL_UY) cpu_model = SKL;
 
     if(!isCPUModelSupported((int)cpu_model))
