--- printing/backend/cups_printer.cc.orig	2025-12-10 15:04:57 UTC
+++ printing/backend/cups_printer.cc
@@ -24,7 +24,7 @@
 #include "printing/print_job_constants.h"
 #include "url/gurl.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "printing/backend/cups_weak_functions.h"
 #endif
 
