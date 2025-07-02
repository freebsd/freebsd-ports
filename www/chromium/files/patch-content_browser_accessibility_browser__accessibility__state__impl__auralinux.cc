--- content/browser/accessibility/browser_accessibility_state_impl_auralinux.cc.orig	2025-07-02 06:08:04 UTC
+++ content/browser/accessibility/browser_accessibility_state_impl_auralinux.cc
@@ -33,7 +33,11 @@ bool CheckCmdlineForOrca(const std::string& cmdline_al
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
@@ -43,6 +47,10 @@ bool CheckCmdlineForOrca(const std::string& cmdline_al
 
 // Returns true if Orca is active.
 bool DiscoverOrca() {
+#if BUILDFLAG(IS_BSD)
+  NOTIMPLEMENTED();
+  return false;
+#else
   // NOTE: this method is run from another thread to reduce jank, since
   // there's no guarantee these system calls will return quickly.
   std::unique_ptr<DIR, decltype(&CloseDir)> proc_dir(opendir("/proc"),
@@ -80,6 +88,7 @@ bool DiscoverOrca() {
   }
 
   return is_orca_active;
+#endif
 }
 
 }  // namespace
