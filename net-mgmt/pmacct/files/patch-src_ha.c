--- src/ha.c.orig	2024-08-01 20:49:09 UTC
+++ src/ha.c
@@ -105,7 +105,7 @@ int bmp_bgp_ha_msglog_init_kafka_host(void)
 
 int bmp_bgp_ha_msglog_init_kafka_host(void)
 {
-  int ret;
+  int ret = 0;
   if (config.bmp_daemon) ret = bmp_ha_msglog_init_kafka_host();
   else if (config.bgp_daemon) ret = bgp_ha_msglog_init_kafka_host();
   return ret;
