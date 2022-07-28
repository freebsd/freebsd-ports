--- content/browser/renderer_host/render_widget_host_view_aura.cc.orig	2022-07-22 17:30:31 UTC
+++ content/browser/renderer_host/render_widget_host_view_aura.cc
@@ -114,7 +114,7 @@
 #include "ui/gfx/gdi_util.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
 #include "content/browser/accessibility/browser_accessibility_auralinux.h"
 #include "ui/base/ime/linux/text_edit_command_auralinux.h"
 #include "ui/base/ime/linux/text_edit_key_bindings_delegate_auralinux.h"
@@ -439,7 +439,7 @@ gfx::NativeViewAccessible RenderWidgetHostViewAura::Ge
   if (manager)
     return ToBrowserAccessibilityWin(manager->GetRoot())->GetCOM();
 
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   BrowserAccessibilityManager* manager =
       host()->GetOrCreateRootBrowserAccessibilityManager();
   if (manager && manager->GetRoot())
@@ -1579,7 +1579,7 @@ bool RenderWidgetHostViewAura::ShouldDoLearning() {
   return GetTextInputManager() && GetTextInputManager()->should_do_learning();
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 bool RenderWidgetHostViewAura::SetCompositionFromExistingText(
     const gfx::Range& range,
     const std::vector<ui::ImeTextSpan>& ui_ime_text_spans) {
@@ -2397,7 +2397,7 @@ bool RenderWidgetHostViewAura::NeedsInputGrab() {
 }
 
 bool RenderWidgetHostViewAura::NeedsMouseCapture() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   return NeedsInputGrab();
 #else
   return false;
@@ -2574,7 +2574,7 @@ void RenderWidgetHostViewAura::ForwardKeyboardEventWit
   if (!target_host)
     return;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   ui::TextEditKeyBindingsDelegateAuraLinux* keybinding_delegate =
       ui::GetTextEditKeyBindingsDelegate();
   std::vector<ui::TextEditCommandAuraLinux> commands;
