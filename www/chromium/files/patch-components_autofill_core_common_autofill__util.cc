--- components/autofill/core/common/autofill_util.cc.orig	2021-09-14 01:51:54 UTC
+++ components/autofill/core/common/autofill_util.cc
@@ -153,7 +153,7 @@ bool SanitizedFieldIsEmpty(const std::u16string& value
 }
 
 bool ShouldAutoselectFirstSuggestionOnArrowDown() {
-#if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
   return true;
 #else
