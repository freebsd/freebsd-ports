--- chrome/browser/ui/views/profiles/profile_menu_view_base.cc.orig	2024-08-01 05:47:53 UTC
+++ chrome/browser/ui/views/profiles/profile_menu_view_base.cc
@@ -687,7 +687,7 @@ void ProfileMenuViewBase::SetProfileIdentityInfo(
 
 // TODO(crbug.com/40118868): Revisit once build flag switch of lacros-chrome is
 // complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   // crbug.com/1161166: Orca does not read the accessible window title of the
   // bubble, so we duplicate it in the top-level menu item. To be revisited
   // after considering other options, including fixes on the AT side.
