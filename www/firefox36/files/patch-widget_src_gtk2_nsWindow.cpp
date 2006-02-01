--- widget/src/gtk2/nsWindow.cpp.orig	Thu Aug 18 10:11:23 2005
+++ widget/src/gtk2/nsWindow.cpp	Sat Jan 28 18:34:03 2006
@@ -148,9 +148,9 @@
                                            GdkEventVisibility *event);
 static gboolean window_state_event_cb     (GtkWidget *widget,
                                            GdkEventWindowState *event);
-static void     style_set_cb              (GtkWidget *widget,
-                                           GtkStyle *previous_style,
-                                           gpointer data);
+static void     theme_changed_cb          (GtkSettings *settings,
+                                           GParamSpec *pspec,
+                                           nsWindow *data);
 #ifdef __cplusplus
 extern "C" {
 #endif /* __cplusplus */
@@ -372,6 +372,10 @@
     mIsDestroyed = PR_TRUE;
     mCreated = PR_FALSE;
 
+    g_signal_handlers_disconnect_by_func(gtk_settings_get_default(),
+                                         (gpointer)G_CALLBACK(theme_changed_cb),
+                                         this);
+
     // ungrab if required
     nsCOMPtr<nsIWidget> rollupWidget = do_QueryReferent(gRollupWindow);
     if (NS_STATIC_CAST(nsIWidget *, this) == rollupWidget.get()) {
@@ -2434,8 +2438,16 @@
                          G_CALLBACK(delete_event_cb), NULL);
         g_signal_connect(G_OBJECT(mShell), "window_state_event",
                          G_CALLBACK(window_state_event_cb), NULL);
-        g_signal_connect(G_OBJECT(mShell), "style_set",
-                         G_CALLBACK(style_set_cb), NULL);
+
+        g_signal_connect_after(gtk_settings_get_default(),
+                               "notify::gtk-theme-name",
+                               G_CALLBACK(theme_changed_cb), this);
+        g_signal_connect_after(gtk_settings_get_default(),
+                               "notify::gtk-key-theme-name",
+                               G_CALLBACK(theme_changed_cb), this);
+        g_signal_connect_after(gtk_settings_get_default(),
+                               "notify::gtk-font-name",
+                               G_CALLBACK(theme_changed_cb), this);
     }
 
     if (mContainer) {
@@ -3916,11 +3928,9 @@
 
 /* static */
 void
-style_set_cb (GtkWidget *widget, GtkStyle *previous_style, gpointer data)
+theme_changed_cb (GtkSettings *settings, GParamSpec *pspec, nsWindow *data)
 {
-    nsWindow *window = get_window_for_gtk_widget(widget);
-    if (window)
-        window->ThemeChanged();
+    data->ThemeChanged();
 }
 
