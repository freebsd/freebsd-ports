--- src/npplayer.cpp.orig	2021-08-07 16:18:34 UTC
+++ src/npplayer.cpp
@@ -21,6 +21,7 @@
 http://devedge-temp.mozilla.org/library/manuals/2002/plugin/1.0/
 http://dbus.freedesktop.org/doc/dbus/libdbus-tutorial.html
 */
+#include <glib.h>
 extern "C" {
 #include <unistd.h>
 #include <string.h>
@@ -32,7 +33,6 @@ extern "C" {
 #include <fcntl.h>
 
 #include <glib/gprintf.h>
-#include <glib.h>
 #include <gdk/gdkx.h>
 #include <gtk/gtk.h>
 
