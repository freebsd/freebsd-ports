--- src/3rdparty/chromium/components/autofill/core/common/autofill_util.cc.orig	2023-04-05 11:05:06 UTC
+++ src/3rdparty/chromium/components/autofill/core/common/autofill_util.cc
@@ -156,7 +156,7 @@ bool SanitizedFieldIsEmpty(const std::u16string& value
 
 bool ShouldAutoselectFirstSuggestionOnArrowDown() {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return false;
