--- boreas/alivedetection.c.orig	2022-07-18 08:40:56 UTC
+++ boreas/alivedetection.c
@@ -39,7 +39,12 @@
 #include <netinet/ip6.h>
 #include <netinet/ip_icmp.h>
 #include <netinet/tcp.h>
-#include <netpacket/packet.h> /* for sockaddr_ll */
+#ifdef AF_LINK
+#   include <net/if_dl.h>
+#endif
+#ifdef AF_PACKET
+#   include <netpacket/packet.h>
+#endif
 #include <pcap.h>
 #include <pthread.h>
 #include <stdlib.h>
@@ -290,8 +295,8 @@ scan (alive_test_t alive_test)
 
   gettimeofday (&end_time, NULL);
 
-  g_message ("Alive scan %s finished in %ld seconds: %d alive hosts of %d.",
-             scan_id, end_time.tv_sec - start_time.tv_sec,
+  g_message ("Alive scan %s finished in %lld seconds: %d alive hosts of %d.",
+             scan_id, (long long)(end_time.tv_sec - start_time.tv_sec),
              g_hash_table_size (scanner.hosts_data->alivehosts),
              number_of_targets);
   g_free (scan_id);
