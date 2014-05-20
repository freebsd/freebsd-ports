--- ./chrome/browser/ui/gtk/first_run_dialog.cc.orig	2014-04-30 22:42:07.000000000 +0200
+++ ./chrome/browser/ui/gtk/first_run_dialog.cc	2014-05-04 14:38:46.000000000 +0200
@@ -132,6 +132,7 @@
   if (dialog_)
     gtk_widget_hide_all(dialog_);
 
+#if !defined(OS_BSD)
   // Check if user has opted into reporting.
   if (report_crashes_ &&
       gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(report_crashes_))) {
@@ -140,6 +141,9 @@
   } else {
     GoogleUpdateSettings::SetCollectStatsConsent(false);
   }
+#else
+  GoogleUpdateSettings::SetCollectStatsConsent(false);
+#endif
 
   // If selected set as default browser.
   if (make_default_ &&
