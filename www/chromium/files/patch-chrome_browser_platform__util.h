--- chrome/browser/platform_util.h.orig	2016-08-04 11:19:03.775212000 -0400
+++ chrome/browser/platform_util.h	2016-08-04 11:19:15.839097000 -0400
@@ -40,7 +40,7 @@
 enum OpenItemType {
   OPEN_FILE,
   OPEN_FOLDER,
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   SHOW_ITEM_IN_FOLDER
 #endif
 };
