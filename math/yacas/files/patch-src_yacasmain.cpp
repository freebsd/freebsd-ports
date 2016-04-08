--- src/yacasmain.cpp.orig	2016-03-11 09:22:12 UTC
+++ src/yacasmain.cpp
@@ -72,6 +72,7 @@
 #if defined (__FreeBSD__) || defined (__DragonFly__)
 #include <stddef.h>
 #include <unistd.h>
+#include <sys/syslimits.h>
 #include <sys/types.h>
 #include <sys/sysctl.h>
 #endif
