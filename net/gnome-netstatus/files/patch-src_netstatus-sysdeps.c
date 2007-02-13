--- src/netstatus-sysdeps.c.orig	Tue Feb 13 04:39:19 2007
+++ src/netstatus-sysdeps.c	Tue Feb 13 17:16:29 2007
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
@@ -486,11 +486,11 @@ get_wi_data (const char *iface,
   level = (int) wreq.wi_val[1];
 
 #ifdef WI_RID_READ_APS
-  if (signal_strength <= 0)
+  if (*signal_strength <= 0)
     {
       /* we fail to get signal strength by usual means, try another way */
       static time_t   last_scan;
-      static long int cached;
+      static int cached;
       time_t          now;
 
       now = time (NULL);
@@ -510,15 +510,15 @@ get_wi_data (const char *iface,
           if (nstations > 0)
 	    {
               w = (struct wi_apinfo *)(((char *) &wreq.wi_val) + sizeof (int));
-              signal_strength = (long int) w->signal;
+              level = w->signal;
             }
 
-            cached = signal_strength;
+            cached = level;
             last_scan = now;
           }
         else
 	  {
-            signal_strength = cached;
+            level = cached;
           }
     }
 #endif
@@ -548,6 +548,8 @@ netstatus_sysdeps_read_iface_wireless_de
       g_strncasecmp (iface, "wi",   2) &&
       g_strncasecmp (iface, "ath",  3) &&
       g_strncasecmp (iface, "ndis", 4) &&
+      g_strncasecmp (iface, "ural", 4) &&
+      g_strncasecmp (iface, "ral",  3) &&
       g_strncasecmp (iface, "ipw",  3) &&
       g_strncasecmp (iface, "iwi",  3) &&
       g_strncasecmp (iface, "acx",  3))
