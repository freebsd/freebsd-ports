--- src/3rdparty/chromium/ui/views/style/platform_style.cc.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/ui/views/style/platform_style.cc
@@ -52,7 +52,7 @@ const bool PlatformStyle::kAdjustBubbleIfOffscreen =
 const bool PlatformStyle::kAdjustBubbleIfOffscreen =
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
     false;
 #else
     true;
@@ -82,7 +82,7 @@ gfx::Range PlatformStyle::RangeToDeleteBackwards(const
 #endif  // !BUILDFLAG(IS_MAC)
 
 #if !BUILDFLAG(ENABLE_DESKTOP_AURA) || \
-    (!BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS))
+    (!BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_BSD))
 // static
 std::unique_ptr<Border> PlatformStyle::CreateThemedLabelButtonBorder(
     LabelButton* button) {
