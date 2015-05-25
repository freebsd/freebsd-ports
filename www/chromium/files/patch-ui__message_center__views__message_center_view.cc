--- ui/message_center/views/message_center_view.cc.orig	2015-04-14 18:31:23.000000000 -0400
+++ ui/message_center/views/message_center_view.cc	2015-04-28 08:26:17.078043000 -0400
@@ -47,7 +47,7 @@
 namespace {
 
 const SkColor kNoNotificationsTextColor = SkColorSetRGB(0xb4, 0xb4, 0xb4);
-#if defined(OS_LINUX) && defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && defined(OS_CHROMEOS)
 const SkColor kTransparentColor = SkColorSetARGB(0, 0, 0, 0);
 #endif
 const int kAnimateClearingNextNotificationDelayMS = 40;
@@ -86,7 +86,7 @@
   label_->SetEnabledColor(kNoNotificationsTextColor);
   // Set transparent background to ensure that subpixel rendering
   // is disabled. See crbug.com/169056
-#if defined(OS_LINUX) && defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && defined(OS_CHROMEOS)
   label_->SetBackgroundColor(kTransparentColor);
 #endif
   AddChildView(label_);
