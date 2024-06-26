--- ui/ozone/platform/wayland/common/wayland_util.cc.orig	2024-06-25 12:08:48 UTC
+++ ui/ozone/platform/wayland/common/wayland_util.cc
@@ -336,7 +336,7 @@ void TransformToWlArray(
 }
 
 base::TimeTicks EventMillisecondsToTimeTicks(uint32_t milliseconds) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // TODO(crbug.com/40287874): `milliseconds` comes from Weston that
   // uses timestamp from libinput, which is different from TimeTicks.
   // Use EventTimeForNow(), for now.
