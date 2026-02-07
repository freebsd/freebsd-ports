--- src/3rdparty/chromium/ui/views/style/platform_style.cc.orig	2021-12-15 16:12:54 UTC
+++ src/3rdparty/chromium/ui/views/style/platform_style.cc
@@ -75,7 +75,7 @@ gfx::Range PlatformStyle::RangeToDeleteBackwards(const
 #endif  // OS_APPLE
 
 #if !BUILDFLAG(ENABLE_DESKTOP_AURA) || \
-    (!defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    (!defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(OS_BSD))
 // static
 std::unique_ptr<Border> PlatformStyle::CreateThemedLabelButtonBorder(
     LabelButton* button) {
