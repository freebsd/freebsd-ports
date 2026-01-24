--- plugins-root/check_icmp.c.orig	2021-02-16 13:28:19 UTC
+++ plugins-root/check_icmp.c
@@ -785,7 +785,12 @@ int main(int argc, char **argv) {
   }
 
   if (icmp_sock) {
-    result = setsockopt(icmp_sock, SOL_IP, IP_TTL, &ttl, sizeof(ttl));
+    if (address_family == AF_INET) {
+      result = setsockopt(icmp_sock, SOL_IP, IP_TTL, &ttl, sizeof(ttl));
+    } else if (address_family == AF_INET6) {
+      int hoplimit = ttl;
+      result = setsockopt(icmp_sock, IPPROTO_IPV6, IPV6_UNICAST_HOPS, &hoplimit, sizeof(hoplimit));
+    }
     if (debug) {
       if (result == -1) {
         printf("setsockopt failed\n");
