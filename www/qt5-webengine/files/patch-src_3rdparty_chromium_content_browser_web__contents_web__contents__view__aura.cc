--- src/3rdparty/chromium/content/browser/web_contents/web_contents_view_aura.cc.orig	2021-12-15 16:12:54 UTC
+++ src/3rdparty/chromium/content/browser/web_contents/web_contents_view_aura.cc
@@ -1211,7 +1211,7 @@ void WebContentsViewAura::OnMouseEvent(ui::MouseEvent*
     // Linux window managers like to handle raise-on-click themselves.  If we
     // raise-on-click manually, this may override user settings that prevent
     // focus-stealing.
-#if !defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if !defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(OS_BSD)
     // It is possible for the web-contents to be destroyed while it is being
     // activated. Use a weak-ptr to track whether that happened or not.
     // More in https://crbug.com/1040725
