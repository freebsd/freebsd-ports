--- components/autofill/core/common/autofill_util.cc.orig	2023-11-22 14:00:11 UTC
+++ components/autofill/core/common/autofill_util.cc
@@ -133,7 +133,7 @@ bool SanitizedFieldIsEmpty(const std::u16string& value
 
 bool ShouldAutoselectFirstSuggestionOnArrowDown() {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return false;
