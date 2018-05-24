--- src/info.c.orig	2013-05-31 00:00:21 UTC
+++ src/info.c
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
@@ -37,6 +41,9 @@
 #include <sys/ioctl.h>
 #include <stdlib.h>
 #include <net/if.h>
+#ifdef __FreeBSD__
+#include <net/if_media.h>
+#endif
 
 #include <glibtop.h>
 #include <glibtop/netlist.h>
@@ -61,6 +68,7 @@ static InfoInterfaceDescription info_iface_desc [] = {
 	{ N_("Ethernet Interface"),      INFO_INTERFACE_ETH,     "16_ethernet.xpm", "eth",        NULL },
 	{ N_("Wireless Interface"),      INFO_INTERFACE_WLAN,    "wavelan-16.png",  "wlan",       NULL },
 	{ N_("Modem Interface"),         INFO_INTERFACE_PPP,     "16_ppp.xpm",      "ppp",        NULL },
+	{ N_("Modem Interface"),         INFO_INTERFACE_PPP,     "16_ppp.xpm",      "tun",        NULL },
 	{ N_("Parallel Line Interface"), INFO_INTERFACE_PLIP,    "16_plip.xpm",     "plip",       NULL },
 	{ N_("Infrared Interface"),      INFO_INTERFACE_IRLAN,   "irda-16.png",     "irlan",      NULL },
 	{ N_("Loopback Interface"),      INFO_INTERFACE_LO,      "16_loopback.xpm", "lo",         NULL },
@@ -131,9 +139,35 @@ info_get_interface_from_dev_name (const gchar *dev_nam
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
