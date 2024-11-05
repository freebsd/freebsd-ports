--- chrome/browser/ui/views/tabs/tab.cc.orig	2024-11-04 08:56:03 UTC
+++ chrome/browser/ui/views/tabs/tab.cc
@@ -625,7 +625,7 @@ void Tab::MaybeUpdateHoverStatus(const ui::MouseEvent&
     return;
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Move the hit test area for hovering up so that it is not overlapped by tab
   // hover cards when they are shown.
   // TODO(crbug.com/41467565): Once Linux/CrOS widget transparency is solved,
