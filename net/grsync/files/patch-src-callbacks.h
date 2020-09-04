--- src/callbacks.h.orig	2013-04-30 11:48:54 UTC
+++ src/callbacks.h
@@ -7,11 +7,11 @@
 #define ICON_PACKAGE PACKAGE_DATA_DIR "/" ICON_SOURCE
 #define ICON_PACKAGE_BUSY PACKAGE_DATA_DIR "/" ICON_SOURCE_BUSY
 
-GtkBuilder *builder;
-GtkWidget *main_window;
-gchar *argv_session, *argv_filename, *icon, *icon_busy;
-gboolean cmdline_session, cmdline_execute, cmdline_stayopen, cmdline_import;
-GtkListStore *liststore_session;
+extern GtkBuilder *builder;
+extern GtkWidget *main_window;
+extern gchar *argv_session, *argv_filename, *icon, *icon_busy;
+extern gboolean cmdline_session, cmdline_execute, cmdline_stayopen, cmdline_import;
+extern GtkListStore *liststore_session;
 
 void save_settings(gchar *session, gchar *filename);
 gboolean load_groups(gchar *session);
