--- includes/site.h.orig	Wed Feb 20 08:46:20 2002
+++ includes/site.h	Sun Apr 21 06:20:20 2002
@@ -89,7 +89,7 @@
 /* Define this if you want all leases written to the lease file, even if
    they are free leases that have never been used. */
 
-#define DEBUG_DUMP_ALL_LEASES
+/* #define DEBUG_DUMP_ALL_LEASES */
 
 /* Define this if you want DHCP failover protocol support in the DHCP
    server. */
