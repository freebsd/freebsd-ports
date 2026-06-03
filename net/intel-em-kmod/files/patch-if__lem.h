--- if_lem.h.orig	2020-04-08 15:13:17 UTC
+++ if_lem.h
@@ -297,7 +297,7 @@ struct adapter {
 
 	/* FreeBSD operating-system-specific structures. */
 	struct e1000_osdep osdep;
-	struct device	*dev;
+	device_t	dev;
 	struct cdev	*led_dev;
 
 	struct resource *memory;
