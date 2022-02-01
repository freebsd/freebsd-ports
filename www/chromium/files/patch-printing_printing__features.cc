--- printing/printing_features.cc.orig	2021-12-14 11:45:09 UTC
+++ printing/printing_features.cc
@@ -7,7 +7,7 @@
 #include "build/chromeos_buildflags.h"
 #include "printing/buildflags/buildflags.h"
 
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
 #include "base/metrics/field_trial_params.h"
 #endif
