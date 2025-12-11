--- chrome/browser/first_run/first_run_dialog.h.orig	2025-12-10 15:04:57 UTC
+++ chrome/browser/first_run/first_run_dialog.h
@@ -9,7 +9,7 @@
 #include "build/build_config.h"
 
 // Hide this function on platforms where the dialog does not exist.
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
 namespace first_run {
 
