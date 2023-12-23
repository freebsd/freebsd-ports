--- components/autofill/core/common/autofill_util.cc.orig	2023-12-23 12:33:28 UTC
+++ components/autofill/core/common/autofill_util.cc
@@ -207,7 +207,7 @@ size_t LevenshteinDistance(std::u16string_view a,
 
 bool ShouldAutoselectFirstSuggestionOnArrowDown() {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return false;
