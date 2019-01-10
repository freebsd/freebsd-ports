--- components/autofill/core/common/autofill_util.cc.orig	2019-01-09 12:24:12.925267000 +0100
+++ components/autofill/core/common/autofill_util.cc	2019-01-09 12:24:28.939308000 +0100
@@ -202,7 +202,7 @@
 }
 
 bool ShouldAutoselectFirstSuggestionOnArrowDown() {
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
   return true;
 #else
   return false;
