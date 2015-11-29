--- dpinger.c.orig	2015-11-25 04:21:35 UTC
+++ dpinger.c
@@ -164,7 +164,7 @@ cksum(
 
     if (len == 1)
     {
-	sum += (uint16_t) *((uint8_t *) p);
+	sum += (uint16_t) *((const uint8_t *) p);
     }
 
     sum = (sum >> 16) + (sum & 0xFFFF);
