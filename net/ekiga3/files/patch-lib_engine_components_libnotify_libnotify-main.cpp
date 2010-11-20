--- lib/engine/components/libnotify/libnotify-main.cpp.orig	2010-08-28 15:04:11.000000000 -0400
+++ lib/engine/components/libnotify/libnotify-main.cpp	2010-08-28 15:01:22.000000000 -0400
@@ -38,6 +38,7 @@
 #include <map>
 #include <tr1/memory>
 
+#include <gtk/gtk.h>
 #include <libnotify/notify.h>
 
 #include "services.h"
