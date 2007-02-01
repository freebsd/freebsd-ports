--- ./src/os/linux/AdapterInfo.cpp.orig	Tue Jan  2 17:19:45 2007
+++ ./src/os/linux/AdapterInfo.cpp	Tue Jan  2 17:20:04 2007
@@ -68,7 +68,7 @@
       else
       {
          rc = TRUE;
-#ifndef __MACH__
+#if !defined(__MACH__) && !defined(__FreeBSD__)
          // Get the number of returned addresses from ifc_len.
          numAddresses = ifconf_structure.ifc_len / sizeof (struct ifreq);
          int j = 0;
