--- src/sflowtool.c.orig	2015-10-06 05:37:21 UTC
+++ src/sflowtool.c
@@ -4308,7 +4308,8 @@ static int ipv4MappedAddress(SFLIPv6 *ip
 static void readPacket(int soc)
 {
   struct sockaddr_in6 peer;
-  int alen, cc;
+  int cc;
+  u_int alen;
 #define MAX_PKT_SIZ 65536
   char buf[MAX_PKT_SIZ];
   alen = sizeof(peer);
