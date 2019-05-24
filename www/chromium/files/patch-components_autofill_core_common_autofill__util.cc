--- components/autofill/core/common/autofill_util.cc.orig	2019-04-30 22:22:41 UTC
+++ components/autofill/core/common/autofill_util.cc
@@ -202,7 +202,7 @@ bool SanitizedFieldIsEmpty(const base::string16& value
 }
 
 bool ShouldAutoselectFirstSuggestionOnArrowDown() {
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
   return true;
 #else
   return false;
