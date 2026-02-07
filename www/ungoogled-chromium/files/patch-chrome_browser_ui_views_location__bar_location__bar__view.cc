--- chrome/browser/ui/views/location_bar/location_bar_view.cc.orig	2026-01-28 20:25:50 UTC
+++ chrome/browser/ui/views/location_bar/location_bar_view.cc
@@ -1777,7 +1777,7 @@ void LocationBarView::OnPopupStateChanged(OmniboxPopup
                      weak_factory_.GetWeakPtr()),
       base::Milliseconds(100));
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (new_state != OmniboxPopupState::kNone) {
     // Close any overlapping user education bubbles when any popup opens.
     // It's not great for promos to overlap the omnibox if the user opens the
