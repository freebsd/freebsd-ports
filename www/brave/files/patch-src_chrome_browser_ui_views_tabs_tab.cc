--- src/chrome/browser/ui/views/tabs/tab.cc.orig	2026-10-18 18:43:23 UTC
+++ src/chrome/browser/ui/views/tabs/tab.cc
@@ -1492,7 +1492,7 @@ void Tab::MaybeUpdateHoverStatus(const u
     return;
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Move the hit test area for hovering up so that it is not overlapped by tab
   // hover cards when they are shown.
   // TODO(crbug.com/41467565): Once Linux/CrOS widget transparency is solved,
