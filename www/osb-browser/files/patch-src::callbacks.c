--- src/callbacks.c.orig	Tue Feb  1 11:46:56 2005
+++ src/callbacks.c	Tue Feb  1 11:49:59 2005
@@ -101,7 +101,7 @@
 on_file_open_activate                  (GtkMenuItem     *menuitem,
                                         gpointer         user_data)
 {
-  g_warning ("%s, user_data: %x", __PRETTY_FUNCTION__, (guint) user_data);
+  g_warning ("%s, user_data: %p", __PRETTY_FUNCTION__, user_data);
 }
 
 
@@ -136,7 +136,7 @@
 on_cut1_activate                       (GtkMenuItem     *menuitem,
                                         gpointer         user_data)
 {
-  g_warning ("%s, user_data: %x", __PRETTY_FUNCTION__, (guint) user_data);
+  g_warning ("%s, user_data: %p", __PRETTY_FUNCTION__, user_data);
 }
 
 
@@ -144,7 +144,7 @@
 on_copy1_activate                      (GtkMenuItem     *menuitem,
                                         gpointer         user_data)
 {
-  g_warning ("%s, user_data: %x", __PRETTY_FUNCTION__, (guint) user_data);
+  g_warning ("%s, user_data: %p", __PRETTY_FUNCTION__, user_data);
 }
 
 
@@ -152,7 +152,7 @@
 on_paste1_activate                     (GtkMenuItem     *menuitem,
                                         gpointer         user_data)
 {
-  g_warning ("%s, user_data: %x", __PRETTY_FUNCTION__, (guint) user_data);
+  g_warning ("%s, user_data: %p", __PRETTY_FUNCTION__, user_data);
 }
 
 
@@ -160,7 +160,7 @@
 on_edit_profiles1_activate             (GtkMenuItem     *menuitem,
                                         gpointer         user_data)
 {
-  g_warning ("%s, user_data: %x", __PRETTY_FUNCTION__, (guint) user_data);
+  g_warning ("%s, user_data: %p", __PRETTY_FUNCTION__, user_data);
 }
 
 
@@ -168,7 +168,7 @@
 on_go1_activate                        (GtkMenuItem     *menuitem,
                                         gpointer         user_data)
 {
-  g_warning ("%s, user_data: %x", __PRETTY_FUNCTION__, (guint) user_data);
+  g_warning ("%s, user_data: %p", __PRETTY_FUNCTION__, user_data);
 }
 
 
@@ -177,7 +177,7 @@
 on_history1_activate                   (GtkMenuItem     *menuitem,
                                         gpointer         user_data)
 {
-  g_warning ("%s, user_data: %x", __PRETTY_FUNCTION__, (guint) user_data);
+  g_warning ("%s, user_data: %p", __PRETTY_FUNCTION__, user_data);
 
 }
 
@@ -186,7 +186,7 @@
 on_bookmarks1_activate                 (GtkMenuItem     *menuitem,
                                         gpointer         user_data)
 {
-  g_warning ("%s, user_data: %x", __PRETTY_FUNCTION__, (guint) user_data);
+  g_warning ("%s, user_data: %p", __PRETTY_FUNCTION__, user_data);
 
 }
 
@@ -195,7 +195,7 @@
 on_add1_activate                       (GtkMenuItem     *menuitem,
                                         gpointer         user_data)
 {
-  g_warning ("%s, user_data: %x", __PRETTY_FUNCTION__, (guint) user_data);
+  g_warning ("%s, user_data: %p", __PRETTY_FUNCTION__, user_data);
 
 }
 
@@ -204,7 +204,7 @@
 on_manage1_activate                    (GtkMenuItem     *menuitem,
                                         gpointer         user_data)
 {
-  g_warning ("%s, user_data: %x", __PRETTY_FUNCTION__, (guint) user_data);
+  g_warning ("%s, user_data: %p", __PRETTY_FUNCTION__, user_data);
 
 }
 
@@ -213,7 +213,7 @@
 on_tools1_activate                     (GtkMenuItem     *menuitem,
                                         gpointer         user_data)
 {
-  g_warning ("%s, user_data: %x", __PRETTY_FUNCTION__, (guint) user_data);
+  g_warning ("%s, user_data: %p", __PRETTY_FUNCTION__, user_data);
 
 }
 
@@ -222,7 +222,7 @@
 on_preferences1_activate               (GtkMenuItem     *menuitem,
                                         gpointer         user_data)
 {
-  g_warning ("%s, user_data: %x", __PRETTY_FUNCTION__, (guint) user_data);
+  g_warning ("%s, user_data: %p", __PRETTY_FUNCTION__, user_data);
 
 }
 
@@ -239,7 +239,7 @@
 on_about1_activate                     (GtkMenuItem     *menuitem,
                                         gpointer         user_data)
 {
-  g_warning ("%s, user_data: %x", __PRETTY_FUNCTION__, (guint) user_data);
+  g_warning ("%s, user_data: %p", __PRETTY_FUNCTION__, user_data);
 
 }
 
@@ -248,7 +248,7 @@
 on_stop_activate                       (GtkButton       *button,
                                         gpointer         user_data)
 {
-  g_warning ("%s, user_data: %x", __PRETTY_FUNCTION__, (guint) user_data);
+  g_warning ("%s, user_data: %p", __PRETTY_FUNCTION__, user_data);
 
 }
 
@@ -258,7 +258,7 @@
 on_exec_activate                       (GtkButton       *button,
                                         gpointer         user_data)
 {
-  g_warning ("%s, user_data: %x", __PRETTY_FUNCTION__, (guint) user_data);
+  g_warning ("%s, user_data: %p", __PRETTY_FUNCTION__, user_data);
 }
 
 
@@ -266,7 +266,7 @@
 on_quit2_activate                      (GtkMenuItem     *menuitem,
                                         gpointer         user_data)
 {
-  g_warning ("%s, user_data: %x", __PRETTY_FUNCTION__, (guint) user_data);
+  g_warning ("%s, user_data: %p", __PRETTY_FUNCTION__, user_data);
 }
 
 
@@ -274,7 +274,7 @@
 on_new1_activate                       (GtkMenuItem     *menuitem,
                                         gpointer         user_data)
 {
-  g_warning ("%s, user_data: %x", __PRETTY_FUNCTION__, (guint) user_data);
+  g_warning ("%s, user_data: %p", __PRETTY_FUNCTION__, user_data);
 }
 
 
@@ -282,7 +282,7 @@
 on_delete1_activate                    (GtkMenuItem     *menuitem,
                                         gpointer         user_data)
 {
-  g_warning ("%s, user_data: %x", __PRETTY_FUNCTION__, (guint) user_data);
+  g_warning ("%s, user_data: %p", __PRETTY_FUNCTION__, user_data);
 }
 
 
@@ -290,7 +290,7 @@
 on_cut2_activate                       (GtkMenuItem     *menuitem,
                                         gpointer         user_data)
 {
-  g_warning ("%s, user_data: %x", __PRETTY_FUNCTION__, (guint) user_data);
+  g_warning ("%s, user_data: %p", __PRETTY_FUNCTION__, user_data);
 }
 
 
