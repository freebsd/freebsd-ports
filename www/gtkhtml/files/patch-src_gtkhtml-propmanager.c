--- src/gtkhtml-propmanager.c.orig	Mon Sep 22 19:08:54 2003
+++ src/gtkhtml-propmanager.c	Mon Sep 22 19:09:24 2003
@@ -24,6 +24,7 @@
 #include <glib.h>
 #include <gnome.h>
 
+#ifdef GTKHTML_HAVE_GCONF
 
 #include "gtkhtml-propmanager.h"
 #include "gtkhtml-properties.h"
@@ -611,3 +612,5 @@
 
 	return propmanager_type;
 }
+
+#endif
