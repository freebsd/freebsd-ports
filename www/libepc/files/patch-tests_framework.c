--- tests/framework.c.orig	2008-08-05 02:14:30.000000000 +0200
+++ tests/framework.c	2008-08-05 02:26:57.000000000 +0200
@@ -24,6 +24,7 @@
 #include <avahi-client/client.h>
 #include <avahi-common/error.h>
 
+#include <sys/socket.h>
 #include <net/if.h>
 #include <sys/ioctl.h>
 
@@ -194,7 +195,11 @@ epc_test_list_ifaces (void)
           goto out;
         }
 
+#ifdef __FreeBSD__
+      ifaces[j].ifidx = req->ifr_index;
+#else
       ifaces[j].ifidx = req->ifr_ifindex;
+#endif
       ifaces[j].mask = epc_test_result;
 
       g_print ("%s: name=%s, ifidx=%u, \n",
