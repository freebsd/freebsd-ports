--- chrome/browser/ui/web_applications/web_app_dialogs.h.orig	2025-01-25 09:34:31 UTC
+++ chrome/browser/ui/web_applications/web_app_dialogs.h
@@ -21,7 +21,7 @@
 #include "ui/gfx/native_widget_types.h"
 
 static_assert(BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
-              BUILDFLAG(IS_CHROMEOS));
+              BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD));
 
 class GURL;
 class Profile;
