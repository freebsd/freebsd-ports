--- chrome/browser/ui/views/app_list/linux/app_list_linux.cc.orig	2017-02-02 02:02:50 UTC
+++ chrome/browser/ui/views/app_list/linux/app_list_linux.cc
@@ -91,7 +91,7 @@ void AppListLinux::MoveNearCursor(app_li
   view->SetBubbleArrow(views::BubbleBorder::FLOAT);
 
   AppListPositioner::ScreenEdge edge;
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   // In the Unity desktop environment, special case SCREEN_EDGE_LEFT. It is
   // always on the left side in Unity, but ShelfLocationInDisplay will not
   // detect this if the shelf is hidden.
