--- src/fping.c.orig	2020-08-05 11:10:13 UTC
+++ src/fping.c
@@ -1060,11 +1060,11 @@ int main(int argc, char** argv)
         exit(num_noaddress ? 2 : 1);
     }
 
-    if (socket4 >= 0) {
+    if (src_addr_set && socket4 >= 0) {
         socket_set_src_addr_ipv4(socket4, &src_addr, (socktype4 == SOCK_DGRAM) ? &ident4 : NULL);
     }
 #ifdef IPV6
-    if (socket6 >= 0) {
+    if (src_addr6_set && socket6 >= 0) {
         socket_set_src_addr_ipv6(socket6, &src_addr6, (socktype6 == SOCK_DGRAM) ? &ident6 : NULL);
     }
 #endif
