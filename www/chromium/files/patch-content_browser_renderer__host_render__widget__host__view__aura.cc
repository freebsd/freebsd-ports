--- content/browser/renderer_host/render_widget_host_view_aura.cc.orig	2016-05-11 19:02:20 UTC
+++ content/browser/renderer_host/render_widget_host_view_aura.cc
@@ -107,7 +107,7 @@
 #include "ui/gfx/win/dpi.h"
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(OS_LINUX) && !defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "content/common/input_messages.h"
 #include "ui/events/linux/text_edit_command_auralinux.h"
 #include "ui/events/linux/text_edit_key_bindings_delegate_auralinux.h"
@@ -734,7 +734,7 @@ gfx::NativeViewId RenderWidgetHostViewAu
   if (host)
     return reinterpret_cast<gfx::NativeViewId>(host->GetAcceleratedWidget());
 #endif
-  return static_cast<gfx::NativeViewId>(NULL);
+  return static_cast<gfx::NativeViewId>(0);
 }
 
 gfx::NativeViewAccessible RenderWidgetHostViewAura::GetNativeViewAccessible() {
@@ -2626,7 +2626,7 @@ bool RenderWidgetHostViewAura::NeedsInpu
 }
 
 bool RenderWidgetHostViewAura::NeedsMouseCapture() {
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   return NeedsInputGrab();
 #endif
   return false;
@@ -2859,7 +2859,7 @@ void RenderWidgetHostViewAura::ForwardKe
   if (!target_host)
     return;
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   ui::TextEditKeyBindingsDelegateAuraLinux* keybinding_delegate =
       ui::GetTextEditKeyBindingsDelegate();
   std::vector<ui::TextEditCommandAuraLinux> commands;
