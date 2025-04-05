--- chrome/browser/ui/views/profiles/profile_menu_view_base.cc.orig	2025-04-04 08:52:13 UTC
+++ chrome/browser/ui/views/profiles/profile_menu_view_base.cc
@@ -650,7 +650,7 @@ void ProfileMenuViewBase::SetProfileIdentityInfo(
       ProfileMenuViewBase::kIdentityImageSize, kIdentityImageBorder,
       /*has_dotted_ring=*/false);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // crbug.com/1161166: Orca does not read the accessible window title of the
   // bubble, so we duplicate it in the top-level menu item. To be revisited
   // after considering other options, including fixes on the AT side.
