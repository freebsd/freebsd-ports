--- chrome/browser/ui/web_applications/web_app_dialogs.h.orig	2025-11-06 10:11:34 UTC
+++ chrome/browser/ui/web_applications/web_app_dialogs.h
@@ -25,7 +25,7 @@
 #include "ui/gfx/native_ui_types.h"
 
 static_assert(BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
-              BUILDFLAG(IS_CHROMEOS));
+              BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD));
 
 class GURL;
 class Profile;
