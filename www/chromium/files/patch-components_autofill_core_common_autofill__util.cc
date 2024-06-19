--- components/autofill/core/common/autofill_util.cc.orig	2024-06-17 12:56:06 UTC
+++ components/autofill/core/common/autofill_util.cc
@@ -132,7 +132,7 @@ bool SanitizedFieldIsEmpty(const std::u16string& value
 
 bool ShouldAutoselectFirstSuggestionOnArrowDown() {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return false;
