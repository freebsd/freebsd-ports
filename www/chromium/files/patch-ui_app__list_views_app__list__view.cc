--- ui/app_list/views/app_list_view.cc.orig	2016-05-11 19:02:35 UTC
+++ ui/app_list/views/app_list_view.cc
@@ -80,7 +80,7 @@ bool SupportsShadow() {
           ::switches::kDisableDwmComposition)) {
     return false;
   }
-#elif defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#elif (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   // Shadows are not supported on (non-ChromeOS) Linux.
   return false;
 #endif
@@ -606,7 +606,7 @@ void AppListView::OnBeforeBubbleWidgetIn
   // the taskbar for these versions of Windows.
   if (base::win::GetVersion() >= base::win::VERSION_WIN7)
     params->force_show_in_taskbar = true;
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   // Set up a custom WM_CLASS for the app launcher window. This allows task
   // switchers in X11 environments to distinguish it from main browser windows.
   params->wm_class_name = kAppListWMClass;
