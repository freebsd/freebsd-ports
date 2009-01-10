--- gtk/gtksignal.h.orig	2008-06-12 01:40:59.000000000 -0400
+++ gtk/gtksignal.h	2008-06-11 18:21:47.000000000 -0400
@@ -29,7 +29,9 @@
 #ifndef __GTK_SIGNAL_H__
 #define __GTK_SIGNAL_H__
 
-#include <gtk/gtk.h>
+#include <gtk/gtkenums.h>
+#include <gtk/gtktypeutils.h>
+#include <gtk/gtkobject.h>
 #include <gtk/gtkmarshal.h>
 
 G_BEGIN_DECLS
