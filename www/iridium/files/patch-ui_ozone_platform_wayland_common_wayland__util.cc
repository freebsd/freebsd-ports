--- ui/ozone/platform/wayland/common/wayland_util.cc.orig	2025-02-22 18:06:53 UTC
+++ ui/ozone/platform/wayland/common/wayland_util.cc
@@ -325,7 +325,7 @@ void SkColorToWlArray(const SkColor4f& color, wl_array
 }
 
 base::TimeTicks EventMillisecondsToTimeTicks(uint32_t milliseconds) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // TODO(crbug.com/40287874): `milliseconds` comes from Weston that
   // uses timestamp from libinput, which is different from TimeTicks.
   // Use EventTimeForNow(), for now.
@@ -367,7 +367,7 @@ bool MaybeHandlePlatformEventForDrag(const ui::Platfor
 }
 
 void RecordConnectionMetrics(wl_display* display) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
   CHECK(display);
 
   // These values are logged to metrics so must not be changed.
