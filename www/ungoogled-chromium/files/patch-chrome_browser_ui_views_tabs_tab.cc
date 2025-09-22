--- chrome/browser/ui/views/tabs/tab.cc.orig	2025-09-22 06:25:21 UTC
+++ chrome/browser/ui/views/tabs/tab.cc
@@ -12,7 +12,6 @@
 #include <memory>
 #include <utility>
 
-#include "base/command_line.h"
 #include "base/debug/alias.h"
 #include "base/functional/bind.h"
 #include "base/i18n/rtl.h"
@@ -678,7 +677,7 @@ void Tab::MaybeUpdateHoverStatus(const ui::MouseEvent&
     return;
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Move the hit test area for hovering up so that it is not overlapped by tab
   // hover cards when they are shown.
   // TODO(crbug.com/41467565): Once Linux/CrOS widget transparency is solved,
@@ -762,13 +761,6 @@ void Tab::HideHover(TabStyle::HideHoverStyle style) {
   DeprecatedLayoutImmediately();
 }
 
-std::u16string Tab::GetRenderedTooltipText(const gfx::Point& p) const {
-  if (base::CommandLine::ForCurrentProcess()->GetSwitchValueASCII("tab-hover-cards") == "tooltip")
-    return GetTooltipText(data_.title, GetAlertStateToShow(data_.alert_state));
-  // Tab hover cards replace tooltips for tabs.
-  return std::u16string();
-}
-
 // This function updates the accessible name for the tab whenever any of the
 // parameters that influence the accessible name change. It ultimately calls
 // BrowserView::GetAccessibleTabLabel to get the updated accessible name.
@@ -1170,11 +1162,7 @@ void Tab::UpdateIconVisibility() {
     // Close button is shown on active tabs regardless of the size.
     showing_close_button_ = true;
 #endif  // BUILDFLAG(IS_CHROMEOS)
-    if (base::CommandLine::ForCurrentProcess()->HasSwitch("hide-tab-close-buttons")) {
-      showing_close_button_ = false;
-    } else {
     available_width -= close_button_width;
-    }
 
     showing_alert_indicator_ =
         has_alert_icon && alert_icon_width <= available_width;
@@ -1203,8 +1191,6 @@ void Tab::UpdateIconVisibility() {
         !controller_->IsLockedForOnTask() &&
 #endif
         large_enough_for_close_button;
-    if (base::CommandLine::ForCurrentProcess()->HasSwitch("hide-tab-close-buttons"))
-      showing_close_button_ = false;
     if (showing_close_button_) {
       available_width -= close_button_width;
     }
