--- chrome/browser/platform_util.h.orig	2019-03-11 22:00:53 UTC
+++ chrome/browser/platform_util.h
@@ -40,7 +40,7 @@ enum OpenOperationResult {
 enum OpenItemType {
   OPEN_FILE,
   OPEN_FOLDER,
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   SHOW_ITEM_IN_FOLDER
 #endif
 };
