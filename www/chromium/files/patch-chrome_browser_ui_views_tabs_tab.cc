--- chrome/browser/ui/views/tabs/tab.cc.orig	2025-03-05 08:14:56 UTC
+++ chrome/browser/ui/views/tabs/tab.cc
@@ -632,7 +632,7 @@ void Tab::MaybeUpdateHoverStatus(const ui::MouseEvent&
     return;
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Move the hit test area for hovering up so that it is not overlapped by tab
   // hover cards when they are shown.
   // TODO(crbug.com/41467565): Once Linux/CrOS widget transparency is solved,
