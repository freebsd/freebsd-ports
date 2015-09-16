--- chrome/browser/ui/browser.cc.orig	2015-04-14 18:31:21.000000000 -0400
+++ chrome/browser/ui/browser.cc	2015-04-28 10:02:57.120071000 -0400
@@ -1284,7 +1284,7 @@
   window_has_shown_ = true;
 
 // CurrentProcessInfo::CreationTime() is missing on some platforms.
-#if defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
   // Measure the latency from startup till the first browser window becomes
   // visible.
   static bool is_first_browser_window = true;
@@ -1300,7 +1300,7 @@
           base::Time::Now() - process_creation_time);
     }
   }
-#endif  // defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_LINUX)
+#endif  // defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
 
   // Nothing to do for non-tabbed windows.
   if (!is_type_tabbed())
