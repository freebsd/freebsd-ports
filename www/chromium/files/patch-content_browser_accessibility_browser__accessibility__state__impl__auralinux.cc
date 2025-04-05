--- content/browser/accessibility/browser_accessibility_state_impl_auralinux.cc.orig	2025-04-04 08:52:13 UTC
+++ content/browser/accessibility/browser_accessibility_state_impl_auralinux.cc
@@ -31,7 +31,11 @@ bool CheckCmdlineForOrca(const std::string& cmdline_al
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
@@ -57,7 +61,9 @@ class BrowserAccessibilityStateImplAuralinux
 
 void BrowserAccessibilityStateImplAuralinux::UpdateHistogramsOnOtherThread() {
   BrowserAccessibilityStateImpl::UpdateHistogramsOnOtherThread();
-
+#if BUILDFLAG(IS_BSD)
+  NOTIMPLEMENTED();
+#else
   // NOTE: this method is run from another thread to reduce jank, since
   // there's no guarantee these system calls will return quickly. Code that
   // needs to run in the UI thread can be run in
@@ -105,6 +111,7 @@ void BrowserAccessibilityStateImplAuralinux::UpdateHis
   } else {
     base::debug::ClearCrashKeyString(ax_orca_crash_key);
   }
+#endif
 }
 
 void BrowserAccessibilityStateImplAuralinux::UpdateUniqueUserHistograms() {
