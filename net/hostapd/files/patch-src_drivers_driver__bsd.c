--- src/drivers/driver_bsd.c.orig	2015-03-15 17:30:39 UTC
+++ src/drivers/driver_bsd.c
@@ -623,7 +623,11 @@ rtbuf_len(void)
 static int bsd_sta_deauth(void *priv, const u8 *own_addr, const u8 *addr,
 			  int reason_code);
 
+#ifdef __DragonFly__
+const char *
+#else
 static const char *
+#endif
 ether_sprintf(const u8 *addr)
 {
 	static char buf[sizeof(MACSTR)];
