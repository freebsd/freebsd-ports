--- chrome/browser/ui/views/location_bar/location_bar_view.cc.orig	2026-07-01 06:24:19 UTC
+++ chrome/browser/ui/views/location_bar/location_bar_view.cc
@@ -1929,7 +1929,7 @@ void LocationBarView::OnPopupStateChanged(OmniboxPopup
     }
   }
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (new_state != OmniboxPopupState::kNone) {
     // Close any overlapping user education bubbles when any popup opens.
     // It's not great for promos to overlap the omnibox if the user opens the
