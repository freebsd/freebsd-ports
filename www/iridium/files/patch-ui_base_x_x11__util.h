--- ui/base/x/x11_util.h.orig	2024-06-25 12:08:48 UTC
+++ ui/base/x/x11_util.h
@@ -256,6 +256,10 @@ COMPONENT_EXPORT(UI_BASE_X) bool IsVulkanSurfaceSuppor
 COMPONENT_EXPORT(UI_BASE_X)
 gfx::ImageSkia GetNativeWindowIcon(intptr_t target_window_id);
 
+// Returns the ICCProfile corresponding to |monitor| using XGetWindowProperty.
+COMPONENT_EXPORT(UI_BASE_X)
+gfx::ICCProfile GetICCProfileForMonitor(int monitor);
+
 }  // namespace ui
 
 #endif  // UI_BASE_X_X11_UTIL_H_
