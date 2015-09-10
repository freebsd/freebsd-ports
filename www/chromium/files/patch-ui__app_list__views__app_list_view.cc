--- ui/app_list/views/app_list_view.cc.orig	2015-04-14 18:31:23.000000000 -0400
+++ ui/app_list/views/app_list_view.cc	2015-04-28 09:00:49.202227000 -0400
@@ -76,7 +76,7 @@
           ::switches::kDisableDwmComposition)) {
     return false;
   }
-#elif defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#elif (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   // Shadows are not supported on (non-ChromeOS) Linux.
   return false;
 #endif
@@ -618,7 +618,7 @@
   // the taskbar for these versions of Windows.
   if (base::win::GetVersion() >= base::win::VERSION_WIN7)
     params->force_show_in_taskbar = true;
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   // Set up a custom WM_CLASS for the app launcher window. This allows task
   // switchers in X11 environments to distinguish it from main browser windows.
   params->wm_class_name = kAppListWMClass;
