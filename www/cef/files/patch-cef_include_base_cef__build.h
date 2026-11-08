--- cef/include/base/cef_build.h.orig	2026-09-06 17:31:54 UTC
+++ cef/include/base/cef_build.h
@@ -78,7 +78,7 @@
 // cef_config.h so any changes must also be reflected in
 // tools/make_config_header.py.
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/base/ozone_buildflags.h"
 #if BUILDFLAG(SUPPORTS_OZONE_X11)
 #define CEF_X11 1
