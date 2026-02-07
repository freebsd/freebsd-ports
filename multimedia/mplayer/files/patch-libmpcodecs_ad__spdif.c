--- libmpcodecs/ad_spdif.c.orig	2024-09-21 09:30:04 UTC
+++ libmpcodecs/ad_spdif.c
@@ -54,7 +54,7 @@ static int read_packet(void *p, uint8_t *buf, int buf_
     return 0;
 }
 
-static int write_packet(void *p, const uint8_t *buf, int buf_size)
+static int write_packet(void *p, uint8_t *buf, int buf_size)
 {
     int len;
     struct spdifContext *ctx = p;
