--- gtk/gtkmm/scale.cc.orig	2013-08-31 20:43:53.000000000 +0200
+++ gtk/gtkmm/scale.cc	2013-08-31 20:49:39.000000000 +0200
@@ -31,6 +31,7 @@
 #include <gtk/gtkhscale.h>
 #include <gtk/gtkvscale.h>
 #include <math.h>
+#include <cstdlib>
 
 namespace Gtk
 {
