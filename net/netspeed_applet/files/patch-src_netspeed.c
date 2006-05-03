--- src/netspeed.c.orig	Mon May  1 19:36:46 2006
+++ src/netspeed.c	Mon May  1 19:42:28 2006
@@ -23,6 +23,7 @@
 #include <panel-applet.h>
 #include <panel-applet-gconf.h>
 #include <gconf/gconf-client.h>
+#include <glibtop.h>
 #include "backend.h"
 #include "netspeed.h"
 
@@ -391,7 +392,7 @@
 
 	devices = get_available_devices();
 	for (tmp = devices; tmp; tmp = g_list_next(tmp)) {
-		if (strcmp(tmp->data, "lo") == 0) continue;
+		if (strcmp(tmp->data, "lo0") == 0) continue;
 		if (strncmp(tmp->data, "dummy", strlen("dummy")) == 0) continue;
 		info = get_device_info(tmp->data);
 		if (info.running) {
@@ -1344,6 +1345,16 @@
 	if (strcmp (iid, "OAFIID:GNOME_NetspeedApplet"))
 		return FALSE;
 
+    /*
+     * Work around a design flaw in libgtop: force an initialisation
+     * of the server, otherwise glibtop_get_netlist() will find that
+     * the server is not needed and glibtop_get_netload() (which needs
+     * the server) will fail.
+     *
+     * Jean-Yves Lefort <jylefort@FreeBSD.org> 20060501
+     */
+    glibtop_init();
+
     icon_theme = gtk_icon_theme_get_default();
     gtk_icon_theme_append_search_path(icon_theme, DATADIR"/pixmaps/"PACKAGE);
 	
@@ -1432,13 +1443,13 @@
 		GList *ptr, *devices = get_available_devices();
 		ptr = devices;
 		while (ptr) { 
-			if (!g_str_equal(ptr->data, "lo"))
+			if (!g_str_equal(ptr->data, "lo0"))
 				applet->devinfo = get_device_info(ptr->data);
 			ptr = g_list_next(ptr);
 		}
 		free_devices_list(devices);		
 	}
-	if (!applet->devinfo.name) applet->devinfo = get_device_info("lo");	
+	if (!applet->devinfo.name) applet->devinfo = get_device_info("lo0");	
 	applet->device_has_changed = TRUE;	
 	
 	applet->tooltips = gtk_tooltips_new();
