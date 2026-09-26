--- content/browser/accessibility/browser_accessibility_state_impl_auralinux.cc.orig	2026-09-25 15:26:43 UTC
+++ content/browser/accessibility/browser_accessibility_state_impl_auralinux.cc
@@ -14,6 +14,7 @@
 #include <sstream>
 #include <string>
 
+#include "base/notimplemented.h"
 #include "base/callback_list.h"
 #include "base/debug/crash_logging.h"
 #include "base/logging.h"
@@ -61,6 +62,10 @@ namespace {
 
 // Returns true if Orca is active.
 bool DiscoverOrca() {
+#if BUILDFLAG(IS_BSD)
+  NOTIMPLEMENTED();
+  return false;
+#else
   // NOTE: this method is run from another thread to reduce jank, since
   // there's no guarantee these system calls will return quickly.
   std::unique_ptr<DIR, decltype(&CloseDir)> proc_dir(opendir("/proc"),
@@ -107,6 +112,7 @@ bool DiscoverOrca() {
   }
 
   return is_orca_active;
+#endif
 }
 
 }  // namespace
