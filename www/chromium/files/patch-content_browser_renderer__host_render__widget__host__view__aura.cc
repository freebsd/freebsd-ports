--- content/browser/renderer_host/render_widget_host_view_aura.cc.orig	2016-07-22 00:06:54.000000000 -0400
+++ content/browser/renderer_host/render_widget_host_view_aura.cc	2016-08-03 12:34:00.357612000 -0400
@@ -105,7 +105,7 @@
 #include "ui/gfx/gdi_util.h"
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(OS_LINUX) && !defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "content/common/input_messages.h"
 #include "ui/events/linux/text_edit_command_auralinux.h"
 #include "ui/events/linux/text_edit_key_bindings_delegate_auralinux.h"
@@ -2376,7 +2376,7 @@
 }
 
 bool RenderWidgetHostViewAura::NeedsMouseCapture() {
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   return NeedsInputGrab();
 #endif
   return false;
@@ -2608,7 +2608,7 @@
   if (!target_host)
     return;
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   ui::TextEditKeyBindingsDelegateAuraLinux* keybinding_delegate =
       ui::GetTextEditKeyBindingsDelegate();
   std::vector<ui::TextEditCommandAuraLinux> commands;
