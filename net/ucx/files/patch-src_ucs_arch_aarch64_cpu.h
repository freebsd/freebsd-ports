--- src/ucs/arch/aarch64/cpu.h.orig	2026-02-17 21:08:28 UTC
+++ src/ucs/arch/aarch64/cpu.h
@@ -15,6 +15,7 @@
 #include <string.h>
 #include <sys/times.h>
 #include <ucs/sys/compiler_def.h>
+#include <ucs/sys/ptr_arith.h>
 #include <ucs/arch/generic/cpu.h>
 #include <ucs/sys/math.h>
 #include <ucs/type/status.h>
