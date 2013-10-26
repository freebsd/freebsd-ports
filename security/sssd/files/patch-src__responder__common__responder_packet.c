From dd2d4ee745852a6d059b07966d1728b10c1240ff Mon Sep 17 00:00:00 2001
From: Lukas Slebodnik <lukas.slebodnik@intrak.sk>
Date: Sat, 4 May 2013 16:08:11 +0200
Subject: [PATCH 17/34] patch-src__responder__common__responder_packet.c

---
 src/responder/common/responder_packet.c | 2 +-
 1 file changed, 1 insertion(+), 1 deletion(-)

diff --git src/responder/common/responder_packet.c src/responder/common/responder_packet.c
index 5132d95..09b8d6d 100644
--- src/responder/common/responder_packet.c
+++ src/responder/common/responder_packet.c
@@ -192,7 +192,7 @@ int sss_packet_recv(struct sss_packet *packet, int fd)
     }
 
     if (rb == 0) {
-        return ENODATA;
+        return ECONNRESET;
     }
 
     if (*packet->len > packet->memsize) {
-- 
1.8.0

