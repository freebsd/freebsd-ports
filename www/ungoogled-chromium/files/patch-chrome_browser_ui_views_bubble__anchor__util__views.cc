--- chrome/browser/ui/views/bubble_anchor_util_views.cc.orig	2022-12-02 17:56:32 UTC
+++ chrome/browser/ui/views/bubble_anchor_util_views.cc
@@ -39,7 +39,7 @@ AnchorConfiguration GetPageInfoAnchorConfiguration(Bro
             views::BubbleBorder::TOP_LEFT};
 
 // TODO(https://crbug.com/1346734): Enable this on all platforms.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (anchor == kLocationBar && browser_view->GetIsPictureInPictureType()) {
     auto* frame_view = static_cast<PictureInPictureBrowserFrameView*>(
         browser_view->frame()->GetFrameView());
