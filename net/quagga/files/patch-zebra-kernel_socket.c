--- zebra/kernel_socket.c.orig	Thu Sep 14 06:47:11 2006
+++ zebra/kernel_socket.c	Thu Feb  1 16:16:35 2007
@@ -585,7 +585,8 @@
   if (ifnlen && strncmp (ifp->name, ifname, INTERFACE_NAMSIZ))
     isalias = 1;
   
-  ifp->metric = ifam->ifam_metric;
+  if (ifam->ifam_metric)
+    ifp->metric = ifam->ifam_metric;
   
   /* Add connected address. */
   switch (sockunion_family (&addr))
