--- src/info.c.orig	Mon Apr  3 15:41:33 2006
+++ src/info.c	Sun Apr 23 21:57:39 2006
@@ -20,6 +20,10 @@
 #include <gtk/gtk.h>
 #include <glib/gi18n.h>
 #include <glib/gprintf.h>
+#include <sys/types.h>
+#include <string.h>
+#include <errno.h>
+#include <unistd.h>
 
 #ifdef HAVE_CONFIG_H
 #  include <config.h>
@@ -38,6 +42,11 @@
 #include <sys/ioctl.h>
 #include <stdlib.h>
 #include <net/if.h>
+#ifdef __FreeBSD__
+#include <sys/sysctl.h>
+#include <net/if_dl.h>
+#include <net/if_media.h>
+#endif
 
 #include "info.h"
 #include "utils.h"
@@ -58,6 +67,7 @@ static InfoInterfaceDescription info_ifa
 	{ N_("Ethernet Interface"),      INFO_INTERFACE_ETH,     "16_ethernet.xpm", "eth",        NULL },
 	{ N_("Wireless Interface"),      INFO_INTERFACE_WLAN,    "wavelan-16.png",  "wlan",       NULL },
 	{ N_("Modem Interface"),         INFO_INTERFACE_PPP,     "16_ppp.xpm",      "ppp",        NULL },
+	{ N_("Modem Interface"),         INFO_INTERFACE_PPP,     "16_ppp.xpm",      "tun",        NULL },
 	{ N_("Parallel Line Interface"), INFO_INTERFACE_PLIP,    "16_plip.xpm",     "plip",       NULL },
 	{ N_("Infrared Interface"),      INFO_INTERFACE_IRLAN,   "irda-16.png",     "irlan",      NULL },
 	{ N_("Loopback Interface"),      INFO_INTERFACE_LO,      "16_loopback.xpm", "lo",         NULL },
@@ -128,9 +138,42 @@ info_get_interface_from_dev_name (const 
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
+#ifdef IFM_ATM
+				case IFM_ATM:
+#endif
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
 			(*iface) = g_strdup_printf ("%s (%s)", _(info_iface_desc[i].name), dev_name);
 			if (info_iface_desc[i].pixbuf == NULL) {
 				path = g_build_filename (PIXMAPS_DIR, info_iface_desc[i].icon, NULL);
@@ -217,38 +260,87 @@ info_nic_update_stats (gpointer data)
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
 	text = info_get_nic (info);
 	if (!text)
 		return FALSE;
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
@@ -276,7 +368,9 @@ info_nic_update_stats (gpointer data)
 	}
 	
 	g_io_channel_unref (io);
-#endif /* defined(__linux__) */
+#if defined(__FreeBSD__)
+	close (pipe_out);
+#endif /* defined(__FreeBSD__) */
 
 	return TRUE;
 }
@@ -405,8 +499,20 @@ info_get_nic_information (const gchar *n
 	InfoIpAddr *ip;
 	gint flags;
 	mii_data_result data;
+#ifdef __FreeBSD__
+	gint hwmib[6];
+	size_t hwlen;
+	gchar *hwbuf;
+	guchar *hwptr;
+	struct if_msghdr *hwifm;
+	struct sockaddr_dl *hwsinptr;
+#endif
 
-	getifaddrs (&ifa0);
+	if (getifaddrs (&ifa0) != 0) {
+		g_warning ("getifaddrs failed: %s", g_strerror (errno));
+		goto fail;
+	}
+	memset (&data, 0, sizeof (data));
 
 	for (ifr6 = ifa0; ifr6; ifr6 = ifr6->ifa_next) {
 		if (strcmp (ifr6->ifa_name, nic) != 0) {
@@ -452,7 +558,9 @@ info_get_nic_information (const gchar *n
 			ifc.ifc_req = (struct ifreq *) buf;
 			ioctl (sockfd, SIOCGIFCONF, &ifc);
 
+#if defined(__linux__)
 			data = mii_get_basic (nic);
+#endif /* defined(__linux__) */
 
 			for (ptr = buf; ptr < buf + ifc.ifc_len;) {
 				ifr = (struct ifreq *) ptr;
@@ -483,6 +591,45 @@ info_get_nic_information (const gchar *n
 				   (int) ((guchar *) &ifrcopy.ifr_hwaddr.sa_data)[3],
 				   (int) ((guchar *) &ifrcopy.ifr_hwaddr.sa_data)[4],
 				   (int) ((guchar *) &ifrcopy.ifr_hwaddr.sa_data)[5]);
+#elif defined(__FreeBSD__)
+			hwmib[0] = CTL_NET;
+			hwmib[1] = AF_ROUTE;
+			hwmib[2] = 0;
+			hwmib[3] = AF_LINK;
+			hwmib[4] = NET_RT_IFLIST;
+			if ((hwmib[5] = if_nametoindex (nic)) == 0) {
+				g_sprintf (dst, NOT_AVAILABLE);
+				goto hwfail;
+			}
+			if (sysctl (hwmib, 6, NULL, &hwlen, NULL, 0) < 0) {
+				g_sprintf (dst, NOT_AVAILABLE);
+				goto hwfail;
+			}
+			if ((hwbuf = g_malloc (hwlen)) == NULL) {
+				g_sprintf (dst, NOT_AVAILABLE);
+				goto hwfail;
+			}
+			if (sysctl (hwmib, 6, hwbuf, &hwlen, NULL, 0) < 0) {
+				g_sprintf (dst, NOT_AVAILABLE);
+				goto hwfail;
+			}
+
+			hwifm = (struct if_msghdr *) hwbuf;
+			hwsinptr = (struct sockaddr_dl *) (hwifm + 1);
+			hwptr = (guchar *) LLADDR (hwsinptr);
+			if (*hwptr != 0 || *(hwptr + 1) != 0 ||
+				*(hwptr + 2) != 0 || *(hwptr + 3) != 0 ||
+				*(hwptr + 4) != 0 || *(hwptr + 5) != 0) {
+				g_sprintf (dst, "%02x:%02x:%02x:%02x:%02x:%02x",
+					*hwptr, *(hwptr + 1), *(hwptr + 2),
+					*(hwptr + 3), *(hwptr + 4), *(hwptr + 5));
+			}
+			else {
+				g_sprintf (dst, NOT_AVAILABLE);
+			}
+			g_free (hwbuf);
+
+hwfail:
 #else
 			g_sprintf (dst, NOT_AVAILABLE);
 #endif /* SIOCGIFHWADDR */
@@ -595,6 +742,8 @@ info_get_nic_information (const gchar *n
 	}
 
 	freeifaddrs (ifa0);
+fail:
+	;
 }
 
 static gint *
