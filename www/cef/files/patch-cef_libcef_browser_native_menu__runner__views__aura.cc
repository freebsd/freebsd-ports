--- cef/libcef/browser/native/menu_runner_views_aura.cc.orig	2026-09-06 17:31:54 UTC
+++ cef/libcef/browser/native/menu_runner_views_aura.cc
@@ -12,7 +12,7 @@
 #include "ui/base/mojom/menu_source_type.mojom.h"
 #include "ui/gfx/geometry/point.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/display/screen.h"
 #include "ui/gfx/x/connection.h"
 #endif
@@ -41,7 +41,7 @@ bool CefMenuRunnerViewsAura::RunContextM
   gfx::Point screen_point = browser->GetScreenPoint(
       gfx::Point(params.x, params.y), /*want_dip_coords=*/true);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (browser->IsWindowless() && parent_widget) {
     // On Linux/X11 with OSR, menus are displayed as top-level override-redirect
     // windows parented to the root window (to avoid clipping). The menu system
