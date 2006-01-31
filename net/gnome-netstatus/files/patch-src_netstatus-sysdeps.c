--- src/netstatus-sysdeps.c.orig	Mon Mar 14 09:34:06 2005
+++ src/netstatus-sysdeps.c	Mon Jan 30 21:44:49 2006
@@ -430,11 +430,11 @@ static inline char *
 get_an_data (const char *iface,
 	     int        *signal_strength)
 {
+  struct an_ltv_status *sts;
+  struct an_req         areq;
 #ifdef AN_RID_RSSI_MAP
   struct an_ltv_rssi_map  an_rssimap;
 #endif
-  struct an_req         areq;
-  struct an_ltv_status *sts;
   int                   level;
   char                 *error = NULL;
   gboolean              rssimap_valid = FALSE;
@@ -548,6 +548,8 @@ netstatus_sysdeps_read_iface_wireless_de
       g_strncasecmp (iface, "wi",   2) &&
       g_strncasecmp (iface, "ath",  3) &&
       g_strncasecmp (iface, "ndis", 4) &&
+      g_strncasecmp (iface, "ural", 4) &&
+      g_strncasecmp (iface, "ral",  3) &&
       g_strncasecmp (iface, "ipw",  3) &&
       g_strncasecmp (iface, "iwi",  3) &&
       g_strncasecmp (iface, "acx",  3))
