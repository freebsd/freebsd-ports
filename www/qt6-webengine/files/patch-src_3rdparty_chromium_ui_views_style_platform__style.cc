--- src/3rdparty/chromium/ui/views/style/platform_style.cc.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/ui/views/style/platform_style.cc
@@ -16,7 +16,7 @@
 #include "ui/views/controls/focusable_border.h"
 #include "ui/views/controls/scrollbar/scroll_bar_views.h"
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/views/controls/scrollbar/overlay_scroll_bar.h"
 #endif
 
@@ -27,7 +27,7 @@ std::unique_ptr<ScrollBar> PlatformStyle::CreateScroll
 // static
 std::unique_ptr<ScrollBar> PlatformStyle::CreateScrollBar(
     ScrollBar::Orientation orientation) {
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return std::make_unique<OverlayScrollBar>(orientation);
 #else
   return std::make_unique<ScrollBarViews>(orientation);
