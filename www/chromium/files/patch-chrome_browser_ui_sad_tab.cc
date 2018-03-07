--- chrome/browser/ui/sad_tab.cc.orig	2018-03-03 21:11:09.039038000 +0100
+++ chrome/browser/ui/sad_tab.cc	2018-03-03 21:11:28.213027000 +0100
@@ -180,7 +180,7 @@
       // Only show incognito suggestion if not already in Incognito mode.
       if (!web_contents_->GetBrowserContext()->IsOffTheRecord())
         message_ids.insert(message_ids.begin(), IDS_SAD_TAB_RELOAD_INCOGNITO);
-#if defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
       // Note: on macOS, Linux and ChromeOS, the first bullet is either one of
       // IDS_SAD_TAB_RELOAD_CLOSE_TABS or IDS_SAD_TAB_RELOAD_CLOSE_NOTABS
       // followed by one of the above suggestions.
