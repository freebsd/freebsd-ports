--- ui/ozone/platform/wayland/common/wayland_util.cc.orig	2025-03-05 16:13:26 UTC
+++ ui/ozone/platform/wayland/common/wayland_util.cc
@@ -420,6 +420,7 @@ void RecordConnectionMetrics(wl_display* display) {
         {"weston", WaylandCompositor::kWeston},
     };
 
+#if !BUILDFLAG(IS_BSD)
     const int fd = wl_display_get_fd(display);
     if (fd == -1) {
       return WaylandCompositor::kUnknown;
@@ -445,6 +446,7 @@ void RecordConnectionMetrics(wl_display* display) {
         return compositor;
       }
     }
+#endif
 
     return WaylandCompositor::kOther;
   };
