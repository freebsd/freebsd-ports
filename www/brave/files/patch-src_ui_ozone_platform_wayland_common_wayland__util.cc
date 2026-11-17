--- src/ui/ozone/platform/wayland/common/wayland_util.cc.orig	2026-10-18 18:43:23 UTC
+++ src/ui/ozone/platform/wayland/common/wayland_util.cc
@@ -417,6 +417,7 @@ void RecordConnectionMetrics(wl_display*
         {"weston", WaylandCompositor::kWeston},
     };
 
+#if !BUILDFLAG(IS_BSD)
     const int fd = wl_display_get_fd(display);
     if (fd == -1) {
       return WaylandCompositor::kUnknown;
@@ -442,6 +443,7 @@ void RecordConnectionMetrics(wl_display*
         return compositor;
       }
     }
+#endif
 
     return WaylandCompositor::kOther;
   };
