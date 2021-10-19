--- ui/views/style/platform_style.cc.orig	2021-09-24 04:26:39 UTC
+++ ui/views/style/platform_style.cc
@@ -52,7 +52,7 @@ const View::FocusBehavior PlatformStyle::kDefaultFocus
 const bool PlatformStyle::kAdjustBubbleIfOffscreen =
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
     false;
 #else
     true;
@@ -82,7 +82,7 @@ gfx::Range PlatformStyle::RangeToDeleteBackwards(const
 #endif  // OS_MAC
 
 #if !BUILDFLAG(ENABLE_DESKTOP_AURA) || \
-    (!defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    (!defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(OS_BSD))
 // static
 std::unique_ptr<Border> PlatformStyle::CreateThemedLabelButtonBorder(
     LabelButton* button) {
