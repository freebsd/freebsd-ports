--- src/netstatus-sysdeps.c.orig	Mon Jun 27 14:29:53 2005
+++ src/netstatus-sysdeps.c	Mon Jun 27 14:30:18 2005
@@ -548,6 +548,8 @@ netstatus_sysdeps_read_iface_wireless_de
       g_strncasecmp (iface, "wi",   2) &&
       g_strncasecmp (iface, "ath",  3) &&
       g_strncasecmp (iface, "ndis", 4) &&
+      g_strncasecmp (iface, "ural", 4) &&
+      g_strncasecmp (iface, "ral",  3) &&
       g_strncasecmp (iface, "ipw",  3) &&
       g_strncasecmp (iface, "iwi",  3) &&
       g_strncasecmp (iface, "acx",  3))
