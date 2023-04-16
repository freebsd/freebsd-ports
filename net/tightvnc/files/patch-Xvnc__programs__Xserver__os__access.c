--- Xvnc/programs/Xserver/os/access.c.orig	2000-06-11 12:00:51 UTC
+++ Xvnc/programs/Xserver/os/access.c
@@ -634,7 +634,7 @@ DefineSelf (fd)
 #endif
     ifc.ifc_len = sizeof (buf);
     ifc.ifc_buf = buf;
-    if (ifioctl (fd, (int) SIOCGIFCONF, (pointer) &ifc) < 0)
+    if (ifioctl (fd, SIOCGIFCONF, (pointer) &ifc) < 0)
         Error ("Getting interface configuration (4)");
 
 #ifdef ISC
