--- src/download.c.orig	2015-02-04 15:42:08.947324133 +0100
+++ src/download.c	2015-02-04 15:46:14.898892516 +0100
@@ -29,6 +29,7 @@
 #include <errno.h>
 #include <locale.h>
 #include <libintl.h>
+#include <netdb.h>
 #include <gtk/gtk.h>
 #if GTK_CHECK_VERSION(3, 0, 0)
 # include <gtk/gtkx.h>
