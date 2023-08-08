--- src/3rdparty/chromium/ui/views/style/platform_style.cc.orig	2023-03-28 19:45:02 UTC
+++ src/3rdparty/chromium/ui/views/style/platform_style.cc
@@ -17,7 +17,7 @@
 #include "ui/views/controls/focusable_border.h"
 #include "ui/views/controls/scrollbar/scroll_bar_views.h"
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/views/controls/scrollbar/overlay_scroll_bar.h"
 #endif
 
@@ -52,7 +52,7 @@ const bool PlatformStyle::kAdjustBubbleIfOffscreen =
 const bool PlatformStyle::kAdjustBubbleIfOffscreen =
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
     false;
 #else
     true;
@@ -60,7 +60,7 @@ std::unique_ptr<ScrollBar> PlatformStyle::CreateScroll
 
 // static
 std::unique_ptr<ScrollBar> PlatformStyle::CreateScrollBar(bool is_horizontal) {
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return std::make_unique<OverlayScrollBar>(is_horizontal);
 #else
   return std::make_unique<ScrollBarViews>(is_horizontal);
