--- gnome-netinfo/netstat.c.orig	Mon Nov 24 18:29:43 2003
+++ gnome-netinfo/netstat.c	Sun Dec  7 01:34:51 2003
@@ -113,7 +113,11 @@
 	}
 	if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON (netinfo->protocol))) {
 		/* Only works for Solaris */
+#ifdef __FreeBSD__
+	    	option = g_strdup ("-a -f inet -ln");
+#else
 		option = g_strdup ("-A inet -ln");
+#endif
 	}
 	if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON (netinfo->multicast))) {
 		/* It works for Solaris and Linux */
@@ -266,7 +270,11 @@
 	g_return_if_fail (line != NULL);
 
 	count = strip_protocol_line (line, &data);
+#ifdef __FreeBSD__
+	if (count == 5 || count == 6 || count == 9 || count == 10) {
+#else
 	if (count == 7 || count == 8) {
+#endif
 #ifdef DEBUG
 		g_print ("%s\t%s:%s\t%s\n", data.protocol,
 			data.ip_src, data.port_src, data.state);
@@ -331,11 +339,42 @@
 strip_protocol_line (gchar * line, netstat_protocol_data *data)
 {
 	gint count = 0;
+#ifdef __FreeBSD__
+	gint a1, a2, a3, a4;
+	gchar s9[30];
+#else
 	gchar s6[30], s7[30];
+#endif
 	gint n2, n3;
 
 	line = g_strdelimit (line, ":", ' ');
 
+#ifdef __FreeBSD__
+	count = sscanf (line, NETSTAT_PROTOCOL_FORMAT,
+			data->protocol, &n2, &n3,
+			&a1, &a2, &a3, &a4, data->port_src,
+			s9, data->state);
+	g_snprintf (data->ip_src, 30, "%d.%d.%d.%d", a1, a2, a3, a4);
+
+	if (count == 9) {
+	    bzero (&(data)->state, 30);
+	}
+
+	if (count == 3) {
+	    /* Handle the *.* entries. */
+	    gchar s5[30];
+	    count = sscanf (line, ALT_NETSTAT_PROTOCOL_FORMAT,
+		    	    data->protocol, &n2, &n3,
+			    data->port_src, s5,
+			    data->state);
+	    g_snprintf (data->ip_src, 30, "*");
+
+	    if (count == 5) {
+		bzero (&(data)->state, 30);
+	    }
+	}
+
+#else
 	count = sscanf (line, NETSTAT_PROTOCOL_FORMAT,
 			data->protocol, &n2, &n3,
 			data->ip_src, data->port_src, 
@@ -344,6 +383,7 @@
 	if (count == 7) {
 		bzero (&(data)->state, 30);
 	}
+#endif
 	
 	return count;
 }
@@ -405,7 +445,11 @@
 	g_return_if_fail (line != NULL);
 
 	count = strip_route_line (line, &data);
+#ifdef __FreeBSD__
+	if (count == 6) {
+#else
 	if (count == 8) {
+#endif
 #ifdef DEBUG
 		g_print ("%s\t%s:%s\t%d\t%s\n", data.destination,
 			data.gateway, data.netmask, data.metric,
@@ -474,11 +518,19 @@
 	gchar flags[30];
 	gint ref, use;
 
+#ifdef __FreeBSD__
+	count = sscanf (line, NETSTAT_ROUTE_FORMAT,
+			data->destination,
+			data->gateway, flags,
+			&ref, &use, data->iface);
+#else
+
 	count = sscanf (line, NETSTAT_ROUTE_FORMAT,
 			data->destination,
 			data->gateway, data->netmask, 
 			flags, &(data)->metric, &ref, &use, 
 			data->iface);
+#endif
 	
 	return count;
 }
@@ -493,7 +545,11 @@
 	renderer = gtk_cell_renderer_text_new ();
 	column =
 	    gtk_tree_view_column_new_with_attributes
+#ifdef __FreeBSD__
+	    (_("Destination/Prefix"), renderer, "text", 0, NULL);
+#else
 	    (_("Destination"), renderer, "text", 0, NULL);
+#endif
 	gtk_tree_view_append_column (widget, column);
 
 	renderer = gtk_cell_renderer_text_new ();
@@ -503,12 +559,14 @@
 	gtk_tree_view_column_set_alignment (column, 0.5);
 	gtk_tree_view_append_column (widget, column);
 
+#ifndef __FreeBSD__
 	renderer = gtk_cell_renderer_text_new ();
 	column =
 	    gtk_tree_view_column_new_with_attributes
 	    (_("Netmask"), renderer, "text", 2, NULL);
 		
 	gtk_tree_view_append_column (widget, column);
+#endif
 
 	renderer = gtk_cell_renderer_text_new ();
 	column =
