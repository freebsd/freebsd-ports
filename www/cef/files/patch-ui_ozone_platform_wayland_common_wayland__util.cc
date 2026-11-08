--- ui/ozone/platform/wayland/common/wayland_util.cc.orig	2026-01-14 08:33:23 UTC
+++ ui/ozone/platform/wayland/common/wayland_util.cc
@@ -417,6 +417,7 @@ void RecordConnectionMetrics(wl_display* display) {
         {"weston", WaylandCompositor::kWeston},
     };
 
+#if !BUILDFLAG(IS_BSD)
     const int fd = wl_display_get_fd(display);
     if (fd == -1) {
       return WaylandCompositor::kUnknown;
@@ -442,6 +443,7 @@ void RecordConnectionMetrics(wl_display* display) {
         return compositor;
       }
     }
+#endif
 
     return WaylandCompositor::kOther;
   };
