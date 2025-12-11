--- printing/backend/print_backend_cups_ipp.cc.orig	2025-12-10 15:04:57 UTC
+++ printing/backend/print_backend_cups_ipp.cc
@@ -21,7 +21,7 @@
 #include "printing/mojom/print.mojom.h"
 #include "printing/units.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "printing/backend/cups_weak_functions.h"
 #endif
 
