--- src/netspeed.c.orig	2006-09-28 05:54:52.000000000 -0400
+++ src/netspeed.c	2008-02-25 14:24:13.000000000 -0500
@@ -23,6 +23,7 @@
 #include <panel-applet.h>
 #include <panel-applet-gconf.h>
 #include <gconf/gconf-client.h>
+#include <glibtop.h>
 #include "backend.h"
 #include "netspeed.h"
 
@@ -1493,7 +1494,7 @@ netspeed_applet_factory(PanelApplet *app
 		GList *ptr, *devices = get_available_devices();
 		ptr = devices;
 		while (ptr) { 
-			if (!g_str_equal(ptr->data, "lo")) {
+			if (!g_str_equal(ptr->data, "lo0")) {
 				get_device_info(ptr->data, &applet->devinfo);
 				break;
 			}
@@ -1502,7 +1503,7 @@ netspeed_applet_factory(PanelApplet *app
 		free_devices_list(devices);		
 	}
 	if (!applet->devinfo.name)
-		get_device_info("lo", &applet->devinfo);	
+		get_device_info("lo0", &applet->devinfo);	
 	applet->device_has_changed = TRUE;	
 	
 	applet->tooltips = gtk_tooltips_new();
