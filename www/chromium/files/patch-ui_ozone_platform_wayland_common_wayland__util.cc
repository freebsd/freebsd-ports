--- ui/ozone/platform/wayland/common/wayland_util.cc.orig	2025-10-30 15:44:36 UTC
+++ ui/ozone/platform/wayland/common/wayland_util.cc
@@ -419,6 +419,7 @@ void RecordConnectionMetrics(wl_display* display) {
         {"weston", WaylandCompositor::kWeston},
     };
 
+#if !BUILDFLAG(IS_BSD)
     const int fd = wl_display_get_fd(display);
     if (fd == -1) {
       return WaylandCompositor::kUnknown;
@@ -444,6 +445,7 @@ void RecordConnectionMetrics(wl_display* display) {
         return compositor;
       }
     }
+#endif
 
     return WaylandCompositor::kOther;
   };
