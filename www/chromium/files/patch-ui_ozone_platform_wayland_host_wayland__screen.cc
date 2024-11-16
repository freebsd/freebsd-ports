--- ui/ozone/platform/wayland/host/wayland_screen.cc.orig	2024-11-14 07:57:23 UTC
+++ ui/ozone/platform/wayland/host/wayland_screen.cc
@@ -47,7 +47,7 @@
 #include "ui/ozone/platform/wayland/host/org_gnome_mutter_idle_monitor.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/base/ui_base_features.h"
 #include "ui/linux/linux_ui.h"
 #endif
@@ -135,7 +135,7 @@ WaylandScreen::WaylandScreen(WaylandConnection* connec
   tablet_state_ = connection_->GetTabletState();
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (connection_->IsUiScaleEnabled() && LinuxUi::instance()) {
     OnDeviceScaleFactorChanged();
     display_scale_factor_observer_.Observe(LinuxUi::instance());
@@ -614,7 +614,7 @@ bool WaylandScreen::VerifyOutputStateConsistentForTest
   return true;
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void WaylandScreen::OnDeviceScaleFactorChanged() {
   CHECK(connection_->IsUiScaleEnabled());
   CHECK(LinuxUi::instance());
