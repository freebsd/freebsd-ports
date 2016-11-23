--- content/browser/renderer_host/render_widget_host_view_aura.cc.orig	2016-10-06 04:02:18.000000000 +0300
+++ content/browser/renderer_host/render_widget_host_view_aura.cc	2016-10-13 07:01:47.728403000 +0300
@@ -106,7 +106,7 @@
 #include "ui/gfx/gdi_util.h"
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(OS_LINUX) && !defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "ui/base/ime/linux/text_edit_command_auralinux.h"
 #include "ui/base/ime/linux/text_edit_key_bindings_delegate_auralinux.h"
 #endif
@@ -2479,7 +2479,7 @@
 }
 
 bool RenderWidgetHostViewAura::NeedsMouseCapture() {
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(OS_LINUX) && !defined(OS_CHROMEOS) || defined(OS_BSD)
   return NeedsInputGrab();
 #endif
   return false;
@@ -2711,7 +2711,7 @@
   if (!target_host)
     return;
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(OS_LINUX) && !defined(OS_CHROMEOS) || defined(OS_BSD)
   ui::TextEditKeyBindingsDelegateAuraLinux* keybinding_delegate =
       ui::GetTextEditKeyBindingsDelegate();
   std::vector<ui::TextEditCommandAuraLinux> commands;
