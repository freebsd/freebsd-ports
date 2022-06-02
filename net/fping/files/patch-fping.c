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
@@ -2299,6 +2299,22 @@ int wait_for_reply(int64_t wait_time)
 #endif
     else {
         return 1;
+    }
+
+    /* Check that src address is one of the hosts we pinged before */
+    int found = 0;
+    for (int i = 0; i < num_hosts; i++) {
+        HOST_ENTRY *h = table[i];
+        if (!addr_cmp((struct sockaddr*)&response_addr, (struct sockaddr*)&h->saddr)) {
+            found = 1;
+            break;
+        }
+    }
+    if (!found) {
+        // char buf[INET6_ADDRSTRLEN];
+        // getnameinfo((struct sockaddr*)&response_addr, sizeof(response_addr), buf, INET6_ADDRSTRLEN, NULL, 0, NI_NUMERICHOST);
+        // fprintf(stderr, "ignoring response from %s\n", buf);
+        return 1; /* packet received, but not from a host we pinged */        
     }
 
     seqmap_value = seqmap_fetch(seq, current_time_ns);
