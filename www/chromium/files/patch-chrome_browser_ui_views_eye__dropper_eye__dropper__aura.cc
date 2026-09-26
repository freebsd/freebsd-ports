--- chrome/browser/ui/views/eye_dropper/eye_dropper_aura.cc.orig	2026-09-25 15:26:43 UTC
+++ chrome/browser/ui/views/eye_dropper/eye_dropper_aura.cc
@@ -13,7 +13,7 @@
 #include "content/public/browser/web_contents.h"
 #include "ui/base/ui_base_features.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/environment.h"
 #include "base/nix/xdg_util.h"
 #if BUILDFLAG(USE_DBUS)
@@ -33,7 +33,7 @@ std::unique_ptr<content::EyeDropper> ShowEyeDropper(
     return nullptr;
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Check the session type from the environment variable (XDG_SESSION_TYPE)
   // instead of the Ozone platform, because XWayland sessions still require
   // the portal eye dropper for reliable screen capture.
