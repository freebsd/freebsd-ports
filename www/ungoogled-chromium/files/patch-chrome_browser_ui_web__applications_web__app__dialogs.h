--- chrome/browser/ui/web_applications/web_app_dialogs.h.orig	2023-12-23 12:33:28 UTC
+++ chrome/browser/ui/web_applications/web_app_dialogs.h
@@ -20,7 +20,7 @@
 #include "ui/gfx/native_widget_types.h"
 
 static_assert(BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
-              BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA));
+              BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD));
 
 class GURL;
 class Profile;
