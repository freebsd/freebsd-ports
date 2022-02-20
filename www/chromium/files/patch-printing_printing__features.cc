--- printing/printing_features.cc.orig	2022-02-07 13:39:41 UTC
+++ printing/printing_features.cc
@@ -8,7 +8,7 @@
 #include "printing/buildflags/buildflags.h"
 
 #if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
-    defined(OS_CHROMEOS)
+    defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "base/metrics/field_trial_params.h"
 #endif
 
