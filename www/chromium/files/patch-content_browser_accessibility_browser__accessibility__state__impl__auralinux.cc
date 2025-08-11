--- content/browser/accessibility/browser_accessibility_state_impl_auralinux.cc.orig	2025-08-07 06:57:29 UTC
+++ content/browser/accessibility/browser_accessibility_state_impl_auralinux.cc
@@ -12,6 +12,8 @@
 #include <sstream>
 #include <string>
 
+#include "base/notimplemented.h"
+
 #include "base/debug/crash_logging.h"
 #include "base/metrics/histogram_macros.h"
 #include "base/task/thread_pool.h"
@@ -34,7 +36,11 @@ bool CheckCmdlineForOrca(const std::string& cmdline_al
   std::string cmdline;
   std::stringstream ss(cmdline_all);
   while (std::getline(ss, cmdline, '\0')) {
+#if BUILDFLAG(IS_BSD)
+    re2::RE2 orca_regex(R"((^|/)(usr/)?(local/)?bin/orca(\s|$))");
+#else
     re2::RE2 orca_regex(R"((^|/)(usr/)?bin/orca(\s|$))");
+#endif
     if (re2::RE2::PartialMatch(cmdline, orca_regex)) {
       return true;  // Orca was found
     }
@@ -44,6 +50,10 @@ bool CheckCmdlineForOrca(const std::string& cmdline_al
 
 // Returns true if Orca is active.
 bool DiscoverOrca() {
+#if BUILDFLAG(IS_BSD)
+  NOTIMPLEMENTED();
+  return false;
+#else
   // NOTE: this method is run from another thread to reduce jank, since
   // there's no guarantee these system calls will return quickly.
   std::unique_ptr<DIR, decltype(&CloseDir)> proc_dir(opendir("/proc"),
@@ -81,6 +91,7 @@ bool DiscoverOrca() {
   }
 
   return is_orca_active;
+#endif
 }
 
 }  // namespace
