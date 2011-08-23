--- lib/engine/components/libnotify/libnotify-main.cpp.orig	2009-09-22 16:27:35.000000000 +0200
+++ lib/engine/components/libnotify/libnotify-main.cpp	2011-03-08 22:11:18.000000000 +0100
@@ -38,6 +38,7 @@
 #include <map>
 #include <tr1/memory>
 
+#include <gtk/gtk.h>
 #include <libnotify/notify.h>
 
 #include "services.h"
@@ -158,7 +159,7 @@ LibNotify::on_notification_added (gmref_
 
   notif = notify_notification_new (notification->get_title ().c_str (),
 				   notification->get_body ().c_str (),
-				   urgency, NULL);
+				   urgency);
 
   g_signal_connect (notif, "closed",
 		    G_CALLBACK (on_notif_closed), notification.get ());
