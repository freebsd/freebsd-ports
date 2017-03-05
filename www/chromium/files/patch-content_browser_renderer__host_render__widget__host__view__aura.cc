--- content/browser/renderer_host/render_widget_host_view_aura.cc.orig	2017-02-02 02:02:53 UTC
+++ content/browser/renderer_host/render_widget_host_view_aura.cc
@@ -107,7 +107,7 @@
 #include "ui/gfx/gdi_util.h"
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
 #include "ui/base/ime/linux/text_edit_command_auralinux.h"
 #include "ui/base/ime/linux/text_edit_key_bindings_delegate_auralinux.h"
 #endif
@@ -1961,7 +1961,7 @@ bool RenderWidgetHostViewAura::NeedsInpu
 }
 
 bool RenderWidgetHostViewAura::NeedsMouseCapture() {
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
   return NeedsInputGrab();
 #endif
   return false;
@@ -2158,7 +2158,7 @@ void RenderWidgetHostViewAura::ForwardKe
   if (!target_host)
     return;
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
   ui::TextEditKeyBindingsDelegateAuraLinux* keybinding_delegate =
       ui::GetTextEditKeyBindingsDelegate();
   std::vector<ui::TextEditCommandAuraLinux> commands;
