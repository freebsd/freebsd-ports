--- src/info.c.orig	Mon Jun 14 06:52:59 2004
+++ src/info.c	Fri Aug 20 15:52:34 2004
@@ -37,6 +37,9 @@
 #include <sys/ioctl.h>
 #include <stdlib.h>
 #include <net/if.h>
+#ifdef __FreeBSD__
+#include <net/if_media.h>
+#endif
 
 #include "info.h"
 #include "utils.h"
@@ -97,9 +100,39 @@
 {
 	gint i;
 	gchar *path;
-	
+	gchar *dev_type = NULL;
+#if defined(__FreeBSD__)
+	int s;
+	struct ifmediareq ifmr;
+
+	if ((s = socket (AF_INET, SOCK_DGRAM, 0)) > -1) {
+
+		(void) memset (&ifmr, 0, sizeof (ifmr));
+		(void) strncpy (ifmr.ifm_name, dev_name, sizeof (ifmr.ifm_name));
+
+		if (ioctl (s, SIOCGIFMEDIA, (caddr_t) &ifmr) > -1) {
+			switch (IFM_TYPE (ifmr.ifm_active)) {
+				case IFM_ETHER:
+					dev_type = "eth";
+					break;
+				case IFM_FDDI:
+				case IFM_TOKEN:
+					dev_type = "other_type";
+					break;
+				case IFM_IEEE80211:
+					dev_type = "wlan";
+					break;
+			}
+		}
+		close (s);
+	}
+#endif /* defined(__FreeBSD__) */
+
+	if (!dev_type)
+		dev_type = (gchar *) dev_name;
+
 	for (i = 0; info_iface_desc[i].name; i++)
-		if (strstr (dev_name, info_iface_desc[i].prefix) == dev_name) {
+		if (strstr (dev_type, info_iface_desc[i].prefix) == dev_type) {
 			(*iface) = g_strdup_printf ("%s (%s)", info_iface_desc[i].name, dev_name);
 			if (info_iface_desc[i].pixbuf == NULL) {
 				path = g_build_filename (PIXMAPS_DIR, info_iface_desc[i].icon, NULL);
@@ -187,17 +220,26 @@
 	gchar tx[10], tx_error[10], tx_drop[10], tx_ovr[10]; 
 	*/
 	gchar iface[30]; /*, flags[30]; */
-	gchar rx_bytes[16], rx_pkt[10], rx_error[10], rx_drop[10], rx_fifo[10];
-	gchar frame[10], compressed[10], multicast[10]; 
-	gchar tx_bytes[16], tx_pkt[10], tx_error[10], tx_drop[10], tx_fifo[10];
+	gchar rx_bytes[16], rx_pkt[10], rx_error[10];
+	gchar tx_bytes[16], tx_pkt[10], tx_error[10];
 	gchar collissions[10];
+#if defined(__linux__)
+	gchar rx_drop[10], rx_fifo[10];
+	gchar frame[10], compressed[10], multicast[10];
+	gchar tx_drop[10], tx_fifo[10];
+#elif defined(__FreeBSD__)
+	char *p;
+	gchar **tokens, **argv;
+	int i;
+	int pipe_out;
+#endif
 
 	GIOChannel *io = NULL;
 	gchar *line;
 	gboolean title = TRUE;
 	const gchar *text;
 	gchar *text_tx_bytes, *text_rx_bytes;
-		
+
 	g_return_val_if_fail (info != NULL, FALSE);
 
 	model = gtk_combo_box_get_model (GTK_COMBO_BOX (info->combo));
@@ -206,21 +248,61 @@
 	else
 		return FALSE;
 	/*text = gtk_entry_get_text (GTK_ENTRY (info->nic));*/
-	
+
 #if defined(__linux__)
 	io = g_io_channel_new_file ("/proc/net/dev", "r", NULL);
-	
+#elif defined(__FreeBSD__)
+	if (!g_shell_parse_argv ("/usr/bin/netstat -in -b -f link", NULL, &argv, NULL)) {
+		return FALSE;
+	}
+	if (!g_spawn_async_with_pipes (NULL, argv, NULL, 0, NULL, NULL, NULL, NULL, &pipe_out, NULL, NULL)) {
+		g_strfreev (argv);
+		return FALSE;
+	}
+
+	g_strfreev (argv);
+
+	io = g_io_channel_unix_new (pipe_out);
+#endif /* defined(__linux__) */
+
 	while (g_io_channel_read_line (io, &line, NULL, NULL, NULL) == G_IO_STATUS_NORMAL) {
 		if (title) {
 			title = FALSE;
 			g_free (line);
 			continue;
 		}
+#if defined(__linux__)
 		line = g_strdelimit (line, ":", ' ');
 		sscanf (line, "%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s", iface,
 			rx_bytes, rx_pkt, rx_error, rx_drop, rx_fifo, frame, 
 		    compressed, multicast, 
 		    tx_bytes, tx_pkt, tx_error, tx_drop, tx_fifo, collissions);
+#elif defined(__FreeBSD__)
+		tokens = (gchar **) g_malloc0 (sizeof (gchar *) * 12);
+		p = strtok (line, " \t\n");
+		/* We only care about 11 fields for now */
+		for (i = 0; i < 11 && p; i++, p = strtok (NULL, " \t\n")) {
+			tokens[i] = g_strdup (p);
+		}
+
+		if (i == 0 || i < 10) {
+			g_free (line);
+			g_strfreev (tokens);
+			continue;
+		}
+
+		g_strlcpy (iface, tokens[0], sizeof (iface));
+
+		g_strlcpy (collissions, tokens[--i], sizeof (collissions));
+		g_strlcpy (tx_bytes, tokens[--i], sizeof (tx_bytes));
+		g_strlcpy (tx_error, tokens[--i], sizeof (tx_error));
+		g_strlcpy (tx_pkt, tokens[--i], sizeof (tx_pkt));
+		g_strlcpy (rx_bytes, tokens[--i], sizeof (rx_bytes));
+		g_strlcpy (rx_error, tokens[--i], sizeof (rx_error));
+		g_strlcpy (rx_pkt, tokens[--i], sizeof (rx_pkt));
+
+		g_strfreev (tokens);
+#endif /* defined(__linux__) */
 
 		if (g_ascii_strcasecmp (iface, text) == 0) {
 			/*
@@ -248,7 +330,9 @@
 	}
 	
 	g_io_channel_unref (io);
-#endif /* defined(__linux__) */
+#if defined(__FreeBSD__)
+	close (pipe_out);
+#endif /* defined(__FreeBSD__) */
 
 	return TRUE;
 }
@@ -384,6 +468,7 @@
 	mii_data_result data;
 
 	getifaddrs (&ifa0);
+	memset (&data, 0, sizeof (data));
 
 	for (ifr6 = ifa0; ifr6; ifr6 = ifr6->ifa_next) {
 		if (strcmp (ifr6->ifa_name, nic) != 0) {
@@ -429,7 +514,9 @@
 			ifc.ifc_req = (struct ifreq *) buf;
 			ioctl (sockfd, SIOCGIFCONF, &ifc);
 
+#if defined(__linux__)
 			data = mii_get_basic (nic);
+#endif /* defined(__linux__) */
 
 			for (ptr = buf; ptr < buf + ifc.ifc_len;) {
 				ifr = (struct ifreq *) ptr;
