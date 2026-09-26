--- printing/backend/cups_weak_functions.h.orig	2026-09-25 15:26:43 UTC
+++ printing/backend/cups_weak_functions.h
@@ -9,7 +9,7 @@
 
 #include "build/build_config.h"
 
-static_assert(BUILDFLAG(IS_LINUX));
+static_assert(BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD));
 
 // Function availability can be tested by checking whether its address is not
 // nullptr. Weak symbols remove the need for platform specific build flags and
