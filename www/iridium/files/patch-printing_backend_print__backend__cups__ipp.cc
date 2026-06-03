--- printing/backend/print_backend_cups_ipp.cc.orig	2026-01-16 14:21:21 UTC
+++ printing/backend/print_backend_cups_ipp.cc
@@ -20,7 +20,7 @@
 #include "printing/mojom/print.mojom.h"
 #include "printing/units.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "printing/backend/cups_weak_functions.h"
 #endif
 
