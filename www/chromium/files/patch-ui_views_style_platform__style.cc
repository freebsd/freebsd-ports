--- ui/views/style/platform_style.cc.orig	2016-05-11 19:02:36 UTC
+++ ui/views/style/platform_style.cc
@@ -34,7 +34,7 @@ scoped_ptr<ScrollBar> PlatformStyle::Cre
 
 #endif
 
-#if !defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if (!defined(OS_LINUX) && !defined(OS_BSD)) || defined(OS_CHROMEOS)
 // static
 scoped_ptr<Border> PlatformStyle::CreateThemedLabelButtonBorder(
     LabelButton* button) {
