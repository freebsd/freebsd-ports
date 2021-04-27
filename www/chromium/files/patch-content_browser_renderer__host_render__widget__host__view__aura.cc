--- content/browser/renderer_host/render_widget_host_view_aura.cc.orig	2021-04-14 18:41:02 UTC
+++ content/browser/renderer_host/render_widget_host_view_aura.cc
@@ -110,7 +110,7 @@
 #include "ui/gfx/gdi_util.h"
 #endif
 
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
 #include "content/browser/accessibility/browser_accessibility_auralinux.h"
 #include "ui/base/ime/linux/text_edit_command_auralinux.h"
 #include "ui/base/ime/linux/text_edit_key_bindings_delegate_auralinux.h"
@@ -466,7 +466,7 @@ gfx::NativeViewAccessible RenderWidgetHostViewAura::Ge
   if (manager)
     return ToBrowserAccessibilityWin(manager->GetRoot())->GetCOM();
 
-#elif defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#elif defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
   BrowserAccessibilityManager* manager =
       host()->GetOrCreateRootBrowserAccessibilityManager();
   if (manager && manager->GetRoot())
@@ -2199,7 +2199,7 @@ bool RenderWidgetHostViewAura::NeedsInputGrab() {
 }
 
 bool RenderWidgetHostViewAura::NeedsMouseCapture() {
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
   return NeedsInputGrab();
 #else
   return false;
@@ -2365,7 +2365,7 @@ void RenderWidgetHostViewAura::ForwardKeyboardEventWit
   if (!target_host)
     return;
 
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
   ui::TextEditKeyBindingsDelegateAuraLinux* keybinding_delegate =
       ui::GetTextEditKeyBindingsDelegate();
   std::vector<ui::TextEditCommandAuraLinux> commands;
