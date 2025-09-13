--- printing/backend/cups_jobs.cc.orig	2025-09-11 13:19:19 UTC
+++ printing/backend/cups_jobs.cc
@@ -31,7 +31,7 @@
 #include "printing/backend/cups_ipp_helper.h"
 #include "printing/printer_status.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "printing/backend/cups_weak_functions.h"
 #endif
 
