--- src/prefs_ui/prefs_privacy.c.orig	Sat Aug 28 00:27:18 2004
+++ src/prefs_ui/prefs_privacy.c	Sat Aug 28 00:27:34 2004
@@ -111,7 +111,7 @@
 {
 	KzPrefsPrivacy *prefsui = g_new0(KzPrefsPrivacy, 1);
 	GtkWidget *main_vbox, *vbox, *hbox, *frame;
-	GtkWidget *radio1, *radio2, *radio3, *radio4;;
+	GtkWidget *radio1, *radio2, *radio3, *radio4;
 	GtkWidget *label, *spin, *check;
 	GtkWidget *button;
 	GtkAdjustment *adj;
