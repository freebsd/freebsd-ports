--- Xvnc/programs/Xserver/os/access.c.orig	2000-06-11 21:00:51.000000000 +0900
+++ Xvnc/programs/Xserver/os/access.c	2007-09-05 12:07:30.000000000 +0900
@@ -634,7 +634,7 @@
 #endif
     ifc.ifc_len = sizeof (buf);
     ifc.ifc_buf = buf;
-    if (ifioctl (fd, (int) SIOCGIFCONF, (pointer) &ifc) < 0)
+    if (ifioctl (fd, SIOCGIFCONF, (pointer) &ifc) < 0)
         Error ("Getting interface configuration (4)");
 
 #ifdef ISC
