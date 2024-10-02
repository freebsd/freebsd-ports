--- ui/ozone/platform/wayland/common/wayland_util.cc.orig	2024-10-01 07:26:23 UTC
+++ ui/ozone/platform/wayland/common/wayland_util.cc
@@ -344,7 +344,7 @@ void TransformToWlArray(
 }
 
 base::TimeTicks EventMillisecondsToTimeTicks(uint32_t milliseconds) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // TODO(crbug.com/40287874): `milliseconds` comes from Weston that
   // uses timestamp from libinput, which is different from TimeTicks.
   // Use EventTimeForNow(), for now.
