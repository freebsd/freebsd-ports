--- ripd/ripd.c.orig	Thu May  4 13:33:44 2006
+++ ripd/ripd.c	Thu May 11 12:58:35 2006
@@ -1822,6 +1822,7 @@
   struct interface *ifp;
   struct connected *ifc;
   struct rip_interface *ri;
+  int vrecv;
 
   /* Fetch socket then register myself. */
   sock = THREAD_FD (t);
@@ -1937,7 +1938,7 @@
     }
 
   /* RIP Version check. RFC2453, 4.6 and 5.1 */
-  int vrecv = ((ri->ri_receive == RI_RIP_UNSPEC) ?
+  vrecv = ((ri->ri_receive == RI_RIP_UNSPEC) ?
                rip->version_recv : ri->ri_receive);
   if ((packet->version == RIPv1) && !(vrecv & RIPv1))
     {
