--- components/autofill/core/common/autofill_util.cc.orig	2021-07-19 18:45:12 UTC
+++ components/autofill/core/common/autofill_util.cc
@@ -161,7 +161,7 @@ bool SanitizedFieldIsEmpty(const std::u16string& value
 }
 
 bool ShouldAutoselectFirstSuggestionOnArrowDown() {
-#if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
   return true;
 #else
