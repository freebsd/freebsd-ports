--- arpcache.c.orig	2022-08-01 22:18:16 UTC
+++ arpcache.c
@@ -153,7 +153,7 @@ void sample_arp_cache() {
     h = arpcache_private[count].mac;
     wack_alarm(ARPING, "Adding: (private) %s [%02x:%02x:%02x:%02x:%02x:%02x]",
                inet_ntoa(sa->sin_addr),
-               *(h++), *(h++), *(h++), *(h++), *(h++), *(h++));
+               h[0], h[1], h[2], h[3], h[4], h[5]);
     count++;
   }
   arpcache_private[count].ip = 0;
