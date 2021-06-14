--- libtransmission/tr-dht.c.orig	2021-06-14 01:02:25 UTC
+++ libtransmission/tr-dht.c
@@ -716,7 +716,7 @@ static int tr_dhtAnnounce(tr_torrent* tor, int af, boo
     {
         rc = dht_search(tor->info.hash, announce ? tr_sessionGetPeerPort(session) : 0, af, callback, NULL);
 
-        if (rc >= 1)
+        if (rc >= 0)
         {
             tr_logAddTorInfo(tor, "Starting %s DHT announce (%s, %d nodes)", af == AF_INET6 ? "IPv6" : "IPv4",
                 tr_dhtPrintableStatus(status), numnodes);
