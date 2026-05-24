--- if_em.h.orig	2020-04-08 15:13:17 UTC
+++ if_em.h
@@ -395,7 +395,7 @@ struct adapter {
 
 	/* FreeBSD operating-system-specific structures. */
 	struct e1000_osdep osdep;
-	struct device	*dev;
+	device_t	dev;
 	struct cdev	*led_dev;
 
 	struct resource *memory;
