--- libgssdp/gssdp-net-posix.c.orig	2019-02-05 21:59:14 UTC
+++ libgssdp/gssdp-net-posix.c
@@ -567,7 +567,7 @@ gssdp_net_list_devices (void)
 
         for (ifa = ifa_list; ifa != NULL; ifa = ifa->ifa_next) {
                 /* Filter for network devices - don't care for addresses */
-                if (ifa->ifa_addr->sa_family != AF_PACKET) {
+                if (ifa->ifa_addr->sa_family != AF_LINK) {
                         continue;
                 }
 
