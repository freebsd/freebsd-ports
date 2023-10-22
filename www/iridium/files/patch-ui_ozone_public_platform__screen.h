--- ui/ozone/public/platform_screen.h.orig	2023-11-22 14:00:11 UTC
+++ ui/ozone/public/platform_screen.h
@@ -15,7 +15,7 @@
 #include "ui/gfx/gpu_extra_info.h"
 #include "ui/gfx/native_widget_types.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/linux/linux_ui.h"
 #endif
 
