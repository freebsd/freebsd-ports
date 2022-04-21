--- chrome/browser/ui/browser_commands.cc.orig	2022-04-21 18:48:31 UTC
+++ chrome/browser/ui/browser_commands.cc
@@ -176,7 +176,7 @@
 #include "chromeos/lacros/lacros_service.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/accessibility/ax_action_data.h"
 #include "ui/accessibility/ax_enums.mojom.h"
 #endif
@@ -1873,7 +1873,7 @@ void FollowSite(Browser* browser, content::WebContents
   feed::FollowSite(web_contents);
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void RunScreenAi(Browser* browser) {
   ui::AXActionData ad;
   ad.action = ax::mojom::Action::kRunScreenAi;
