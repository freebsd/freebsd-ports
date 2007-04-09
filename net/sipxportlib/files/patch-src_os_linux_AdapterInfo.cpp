--- src/os/linux/AdapterInfo.cpp.orig	Wed Aug 30 01:18:24 2006
+++ src/os/linux/AdapterInfo.cpp	Sat Apr  7 20:15:33 2007
@@ -21,6 +21,7 @@
 #include <sys/types.h>
 #include <unistd.h>
 #include <net/if.h>
+#include <stdint.h>
 
 // APPLICATION INCLUDES
 #include <os/HostAdapterAddress.h>
@@ -68,7 +69,7 @@
       else
       {
          rc = TRUE;
-#ifndef __MACH__
+#if !defined(__MACH__) && !defined(__FreeBSD__)
          // Get the number of returned addresses from ifc_len.
          numAddresses = ifconf_structure.ifc_len / sizeof (struct ifreq);
          int j = 0;
@@ -94,7 +95,7 @@
          numAddresses = j;
 #else
          void* ptr;
-         for (ptr = ifreq_array; (int) ptr < ((int) ifreq_array) + ifconf_structure.ifc_len; )
+         for (ptr = ifreq_array; (uintptr_t) ptr < ((uintptr_t) ifreq_array) + ifconf_structure.ifc_len; )
          {
             struct ifreq* ifr = (struct ifreq*) ptr;
             
@@ -102,7 +103,7 @@
             if (ifr->ifr_addr.sa_len > sizeof(struct sockaddr))
                len = ifr->ifr_addr.sa_len;
 
-            ptr = (void *) ((int) ptr + sizeof(ifr->ifr_name) + len);
+            ptr = (void *) ((uintptr_t) ptr + sizeof(ifr->ifr_name) + len);
 
             // The body of this if statement should mirror the for loop above...
             if (ifr->ifr_addr.sa_family == AF_INET)
