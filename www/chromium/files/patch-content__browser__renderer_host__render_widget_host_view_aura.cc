--- content/browser/renderer_host/render_widget_host_view_aura.cc.orig	2016-01-21 16:05:17.322098582 +0100
+++ content/browser/renderer_host/render_widget_host_view_aura.cc	2016-01-21 16:08:52.682084606 +0100
@@ -102,7 +102,7 @@
 #include "ui/gfx/win/dpi.h"
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if defined(OS_LINUX) && !defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "content/common/input_messages.h"
 #include "ui/events/linux/text_edit_command_auralinux.h"
 #include "ui/events/linux/text_edit_key_bindings_delegate_auralinux.h"
@@ -736,7 +736,7 @@
   if (host)
     return reinterpret_cast<gfx::NativeViewId>(host->GetAcceleratedWidget());
 #endif
-  return static_cast<gfx::NativeViewId>(NULL);
+  return static_cast<gfx::NativeViewId>(0);
 }
 
 gfx::NativeViewAccessible RenderWidgetHostViewAura::GetNativeViewAccessible() {
@@ -2543,7 +2543,7 @@
 }
 
 bool RenderWidgetHostViewAura::NeedsMouseCapture() {
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   return NeedsInputGrab();
 #endif
   return false;
@@ -2774,7 +2774,7 @@
   if (host_->delegate())
     target_host = host_->delegate()->GetFocusedRenderWidgetHost(host_);
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   ui::TextEditKeyBindingsDelegateAuraLinux* keybinding_delegate =
       ui::GetTextEditKeyBindingsDelegate();
   std::vector<ui::TextEditCommandAuraLinux> commands;
