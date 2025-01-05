--- src/3rdparty/chromium/components/autofill/core/common/autofill_util.cc.orig	2024-02-23 21:04:38 UTC
+++ src/3rdparty/chromium/components/autofill/core/common/autofill_util.cc
@@ -130,7 +130,7 @@ bool SanitizedFieldIsEmpty(const std::u16string& value
 
 bool ShouldAutoselectFirstSuggestionOnArrowDown() {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return false;
