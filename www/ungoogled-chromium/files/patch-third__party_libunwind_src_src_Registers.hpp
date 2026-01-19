--- third_party/libunwind/src/src/Registers.hpp.orig	2026-01-19 10:05:45 UTC
+++ third_party/libunwind/src/src/Registers.hpp
@@ -20,7 +20,7 @@
 #include "libunwind_ext.h"
 #include "shadow_stack_unwind.h"
 
-#if __has_include(<sys/auxv.h>)
+#if __has_include(<sys/auxv.h>) && !defined(__OpenBSD__) && !defined(__FreeBSD__)
 #include <sys/auxv.h>
 #define HAVE_SYS_AUXV_H
 #endif
