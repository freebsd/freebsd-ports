--- chrome/browser/ui/gtk/first_run_dialog.cc.orig	2013-09-25 23:01:19.000000000 +0300
+++ chrome/browser/ui/gtk/first_run_dialog.cc	2013-09-25 23:11:03.000000000 +0300
@@ -160,6 +160,7 @@
   if (dialog_)
     gtk_widget_hide_all(dialog_);
 
+#if !defined(OS_BSD)
   // Check if user has opted into reporting.
   if (report_crashes_ &&
       gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(report_crashes_))) {
@@ -168,6 +169,9 @@
   } else {
     GoogleUpdateSettings::SetCollectStatsConsent(false);
   }
+#else
+  GoogleUpdateSettings::SetCollectStatsConsent(false);
+#endif
 
   // If selected set as default browser.
   if (make_default_ &&
