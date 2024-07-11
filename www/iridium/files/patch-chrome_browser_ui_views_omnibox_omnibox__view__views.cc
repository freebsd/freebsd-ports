--- chrome/browser/ui/views/omnibox/omnibox_view_views.cc.orig	2024-06-25 12:08:48 UTC
+++ chrome/browser/ui/views/omnibox/omnibox_view_views.cc
@@ -1951,7 +1951,7 @@ void OmniboxViewViews::MaybeAddSendTabToSelfItem(
 }
 
 void OmniboxViewViews::OnPopupOpened() {
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // It's not great for promos to overlap the omnibox if the user opens the
   // drop-down after showing the promo. This especially causes issues on Mac and
   // Linux due to z-order/rendering issues, see crbug.com/1225046 and
