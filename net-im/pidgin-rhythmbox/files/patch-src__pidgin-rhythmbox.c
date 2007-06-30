--- ./src/pidgin-rhythmbox.c.orig	2007-06-28 14:14:13.000000000 +0400
+++ ./src/pidgin-rhythmbox.c	2007-06-28 14:14:22.000000000 +0400
@@ -26,7 +26,7 @@
 #include <string.h>
 #include <glib.h>
 #include <dbus/dbus.h>
-#include <dbus/dbus-glib.h>
+#include <dbus/dbus-glib-lowlevel.h>
 
 #include "gtkplugin.h"
 #include "util.h"
