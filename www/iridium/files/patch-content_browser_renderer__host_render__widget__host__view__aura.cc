--- content/browser/renderer_host/render_widget_host_view_aura.cc.orig	2025-09-11 13:19:19 UTC
+++ content/browser/renderer_host/render_widget_host_view_aura.cc
@@ -122,7 +122,7 @@
 #include "ui/gfx/gdi_util.h"
 #endif  // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/accessibility/platform/browser_accessibility_auralinux.h"
 #include "ui/base/ime/linux/text_edit_command_auralinux.h"
 #include "ui/base/ime/text_input_flags.h"
@@ -479,7 +479,7 @@ gfx::NativeViewAccessible RenderWidgetHostViewAura::Ge
     return ToBrowserAccessibilityWin(manager->GetBrowserAccessibilityRoot())
         ->GetCOM();
 
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   ui::BrowserAccessibilityManager* manager =
       host()->GetOrCreateRootBrowserAccessibilityManager();
   if (manager && manager->GetBrowserAccessibilityRoot())
@@ -1883,7 +1883,7 @@ bool RenderWidgetHostViewAura::ShouldDoLearning() {
   return host() && host()->delegate() && host()->delegate()->ShouldDoLearning();
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 bool RenderWidgetHostViewAura::SetCompositionFromExistingText(
     const gfx::Range& range,
     const std::vector<ui::ImeTextSpan>& ui_ime_text_spans) {
@@ -2866,7 +2866,7 @@ bool RenderWidgetHostViewAura::NeedsInputGrab() {
 }
 
 bool RenderWidgetHostViewAura::NeedsMouseCapture() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return NeedsInputGrab();
 #else
   return false;
@@ -3050,7 +3050,7 @@ void RenderWidgetHostViewAura::ForwardKeyboardEventWit
   if (!target_host)
     return;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   auto* linux_ui = ui::LinuxUi::instance();
   if (!event.skip_if_unhandled && linux_ui && event.os_event) {
     const auto command = linux_ui->GetTextEditCommandForEvent(
