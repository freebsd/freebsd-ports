--- src/netspeed.c.orig	Sat Apr 15 03:17:56 2006
+++ src/netspeed.c	Sat Apr 15 03:27:09 2006
@@ -164,11 +164,17 @@ change_icons(NetspeedApplet *applet)
 	{
 		if (strstr(device, "ppp"))
 			type = gdk_pixbuf_new_from_xpm_data(ICON_PPP);
-		else if (!strcmp(device, "lo"))
+		else if (strstr(device, "tun"))
+			type = gdk_pixbuf_new_from_xpm_data(ICON_PPP);
+		else if (strstr(device, "lo"))
 			type = gdk_pixbuf_new_from_xpm_data(ICON_LO);
-		else if (strstr(device, "lip"))
+		else if (strstr(device, "plip"))
 			type = gdk_pixbuf_new_from_xpm_data(ICON_PLIP);
-		else if (strstr(device, "wlan"))
+		else if (strstr(device, "ath") || strstr(device, "an") ||
+			 strstr(device, "awi") || strstr(device, "iwi") ||
+			 strstr(device, "ipw") || strstr(device, "ndis") ||
+			 strstr(device, "ral") || strstr(device, "ural") ||
+			 strstr(device, "wi") || strstr(device, "wl"))
 			type = gdk_pixbuf_new_from_xpm_data(ICON_WLAN);
 		else
 			type = gdk_pixbuf_new_from_xpm_data(ICON_ETH);
@@ -386,7 +392,7 @@ search_for_up_if(NetspeedApplet *applet)
 	
 	devices = get_available_devices();
 	for (tmp = devices; tmp; tmp = g_list_next(tmp)) {
-		if (!g_str_equal(tmp->data, "lo")) {
+		if (!g_str_equal(tmp->data, "lo0")) {
 			info = get_device_info(tmp->data);
 			if (info.running) {
 				free_device_info(&applet->devinfo);
@@ -1387,13 +1393,13 @@ netspeed_applet_factory(PanelApplet *app
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
