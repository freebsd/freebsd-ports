--- src/base/trace_event/memory_infra_background_allowlist.cc.orig	2026-06-01 00:00:00 UTC
+++ src/base/trace_event/memory_infra_background_allowlist.cc
@@ -384,9 +384,12 @@
 }
 
 bool IsMemoryAllocatorDumpNameInAllowlist(const std::string& name) {
+#if !defined(BRAVE_REDIRECT_CC_BUILD)
+  // Defined in the chromium_src override, which is unavailable here.
   if (IsMemoryAllocatorDumpNameInBraveAllowlist(name)) {
     return true;
   }
+#endif
   // Global dumps that are of hex digits are all allowed for background use.
   if (base::StartsWith(name, "global/", CompareCase::SENSITIVE)) {
     for (size_t i = strlen("global/"); i < name.size(); i++) {
