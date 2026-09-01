--- chrome/browser/ui/views/location_bar/location_bar_view.cc.orig	2026-08-31 10:59:09 UTC
+++ chrome/browser/ui/views/location_bar/location_bar_view.cc
@@ -1817,7 +1817,7 @@ void LocationBarView::OnPopupStateChanged(OmniboxPopup
     }
   }
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (new_state != OmniboxPopupState::kNone) {
     // Close any overlapping user education bubbles when any popup opens.
     // It's not great for promos to overlap the omnibox if the user opens the
