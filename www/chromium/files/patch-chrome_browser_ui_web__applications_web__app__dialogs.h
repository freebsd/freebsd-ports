--- chrome/browser/ui/web_applications/web_app_dialogs.h.orig	2025-09-06 10:01:20 UTC
+++ chrome/browser/ui/web_applications/web_app_dialogs.h
@@ -24,7 +24,7 @@
 #include "ui/gfx/native_widget_types.h"
 
 static_assert(BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
-              BUILDFLAG(IS_CHROMEOS));
+              BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD));
 
 class GURL;
 class Profile;
