--- chrome/browser/ui/views/location_bar/location_bar_view.cc.orig	2026-06-05 13:45:06 UTC
+++ chrome/browser/ui/views/location_bar/location_bar_view.cc
@@ -1922,7 +1922,7 @@ void LocationBarView::OnPopupStateChanged(OmniboxPopup
     }
   }
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (new_state != OmniboxPopupState::kNone) {
     // Close any overlapping user education bubbles when any popup opens.
     // It's not great for promos to overlap the omnibox if the user opens the
