--- onnxruntime/core/mlas/lib/platform.cpp.orig	2026-01-02 14:17:14 UTC
+++ onnxruntime/core/mlas/lib/platform.cpp
@@ -32,6 +32,9 @@ --*/
 #define POWER_10_ANDUP (POWER_10)
 #include <sys/systemcfg.h>
 #define __power_10_andup() (_system_configuration.implementation & POWER_10_ANDUP)
+#elif defined(__FreeBSD__)
+#include <machine/cpu.h>
+#include <sys/auxv.h>
 #endif
 #endif
 
