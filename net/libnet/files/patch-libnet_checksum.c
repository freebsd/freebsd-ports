--- src/libnet_checksum.c.orig	Mon Mar  1 22:26:12 2004
+++ src/libnet_checksum.c	Mon Aug 25 15:44:12 2008
@@ -42,8 +42,10 @@
 libnet_in_cksum(u_int16_t *addr, int len)
 {
     int sum;
+    u_int16_t last_byte;
 
     sum = 0;
+    last_byte = 0;
 
     while (len > 1)
     {
@@ -52,7 +54,8 @@
     }
     if (len == 1)
     {
-        sum += *(u_int16_t *)addr;
+        *(u_int8_t*)&last_byte = *(u_int8_t*)addr;
+        sum += last_byte;
     }
 
     return (sum);
