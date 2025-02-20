--- chrome/browser/glic/launcher/glic_status_icon.cc.orig	2025-02-20 09:59:21 UTC
+++ chrome/browser/glic/launcher/glic_status_icon.cc
@@ -30,7 +30,7 @@ GlicStatusIcon::GlicStatusIcon(GlicController* control
   // TODO(crbug.com/382287104): Use correct icon.
   // TODO(crbug.com/386839488): Chose color based on system theme.
   gfx::ImageSkia status_tray_icon = gfx::CreateVectorIcon(kGlicButtonIcon,
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
                                                           SK_ColorWHITE
 #else
                                                           SK_ColorBLACK
