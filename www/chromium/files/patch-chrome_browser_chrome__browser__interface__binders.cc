--- chrome/browser/chrome_browser_interface_binders.cc.orig	2022-02-07 13:39:41 UTC
+++ chrome/browser/chrome_browser_interface_binders.cc
@@ -97,7 +97,7 @@
 #endif  // BUILDFLAG(FULL_SAFE_BROWSING)
 
 #if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS_ASH)
+    BUILDFLAG(IS_CHROMEOS_ASH) || defined(OS_BSD)
 #include "chrome/browser/ui/webui/connectors_internals/connectors_internals.mojom.h"
 #include "chrome/browser/ui/webui/connectors_internals/connectors_internals_ui.h"
 #endif
@@ -165,7 +165,7 @@
 #endif  // defined(OS_ANDROID)
 
 #if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
-    defined(OS_CHROMEOS)
+    defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "chrome/browser/ui/webui/discards/discards.mojom.h"
 #include "chrome/browser/ui/webui/discards/discards_ui.h"
 #include "chrome/browser/ui/webui/discards/site_data.mojom.h"
@@ -654,7 +654,7 @@ void PopulateChromeFrameBinders(
 #endif
 
 #if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
-    defined(OS_CHROMEOS)
+    defined(OS_CHROMEOS) || defined(OS_BSD)
   if (!render_frame_host->GetParent()) {
     map->Add<chrome::mojom::DraggableRegions>(
         base::BindRepeating(&DraggableRegionsHostImpl::CreateIfAllowed));
@@ -662,7 +662,7 @@ void PopulateChromeFrameBinders(
 #endif
 
 #if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_MAC) || \
-    defined(OS_WIN)
+    defined(OS_WIN) || defined(OS_BSD)
   if (base::FeatureList::IsEnabled(blink::features::kDesktopPWAsSubApps) &&
       !render_frame_host->GetParent()) {
     map->Add<blink::mojom::SubAppsProvider>(
@@ -702,7 +702,7 @@ void PopulateChromeWebUIFrameBinders(
       SegmentationInternalsUI>(map);
 
 #if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS_ASH)
+    BUILDFLAG(IS_CHROMEOS_ASH) || defined(OS_BSD)
   RegisterWebUIControllerInterfaceBinder<
       connectors_internals::mojom::PageHandler,
       enterprise_connectors::ConnectorsInternalsUI>(map);
@@ -1003,7 +1003,7 @@ void PopulateChromeWebUIFrameBinders(
 #endif
 
 #if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
-    defined(OS_CHROMEOS)
+    defined(OS_CHROMEOS) || defined(OS_BSD)
   RegisterWebUIControllerInterfaceBinder<discards::mojom::DetailsProvider,
                                          DiscardsUI>(map);
 
