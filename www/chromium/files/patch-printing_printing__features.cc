--- printing/printing_features.cc.orig	2022-02-28 16:54:41 UTC
+++ printing/printing_features.cc
@@ -8,7 +8,7 @@
 #include "printing/buildflags/buildflags.h"
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "base/metrics/field_trial_params.h"
 #endif
 
