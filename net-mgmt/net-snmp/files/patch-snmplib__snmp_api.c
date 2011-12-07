--- ./snmplib/snmp_api.c.orig	2011-12-07 17:39:10.000000000 -0500
+++ ./snmplib/snmp_api.c	2011-12-07 17:46:39.000000000 -0500
@@ -704,6 +704,8 @@
 
     netsnmp_ds_set_int(NETSNMP_DS_LIBRARY_ID, 
                        NETSNMP_DS_LIB_HEX_OUTPUT_LENGTH, 16);
+    netsnmp_ds_set_int(NETSNMP_DS_LIBRARY_ID, NETSNMP_DS_LIB_RETRIES,
+                       DEFAULT_RETRIES);
 
 #ifdef NETSNMP_USE_REVERSE_ASNENCODING
     netsnmp_ds_set_boolean(NETSNMP_DS_LIBRARY_ID, 
@@ -6032,8 +6034,9 @@
              */
             requests++;
             for (rp = slp->internal->requests; rp; rp = rp->next_request) {
-                if ((!timerisset(&earliest)
-                     || (timercmp(&rp->expire, &earliest, <)))) {
+                if (!timerisset(&earliest)
+                    || (timerisset(&rp->expire)
+                        && timercmp(&rp->expire, &earliest, <))) {
                     earliest = rp->expire;
                     DEBUGMSG(("verbose:sess_select","(to in %d.%06d sec) ",
                                (int)earliest.tv_sec, (int)earliest.tv_usec));
