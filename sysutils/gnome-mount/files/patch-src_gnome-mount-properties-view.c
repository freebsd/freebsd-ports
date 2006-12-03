--- src/gnome-mount-properties-view.c.orig	Sun Dec  3 02:24:16 2006
+++ src/gnome-mount-properties-view.c	Sun Dec  3 02:25:20 2006
@@ -30,6 +30,7 @@
 #include <glib/gi18n.h>
 #include <gtk/gtk.h>
 #include <glade/glade.h>
+#include <libgnomevfs/gnome-vfs-utils.h>
 #include <time.h>
 #include <sys/time.h>
 #include <string.h>
