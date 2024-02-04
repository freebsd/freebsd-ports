--- components/autofill/core/common/autofill_util.cc.orig	2024-02-04 14:46:08 UTC
+++ components/autofill/core/common/autofill_util.cc
@@ -207,7 +207,7 @@ size_t LevenshteinDistance(std::u16string_view a,
 
 bool ShouldAutoselectFirstSuggestionOnArrowDown() {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return false;
