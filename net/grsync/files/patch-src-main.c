--- src/main.c.orig	2013-04-30 11:48:54 UTC
+++ src/main.c
@@ -10,6 +10,12 @@
 #	include <libosso.h>
 #endif
 
+GtkBuilder *builder;
+GtkWidget *main_window;
+gchar *argv_session, *argv_filename, *icon, *icon_busy;
+gboolean cmdline_session, cmdline_execute, cmdline_stayopen, cmdline_import;
+GtkListStore *liststore_session;
+
 int main (int argc, char *argv[]) {
 #ifdef ENABLE_NLS
 	bindtextdomain(GETTEXT_PACKAGE, PACKAGE_LOCALE_DIR);
