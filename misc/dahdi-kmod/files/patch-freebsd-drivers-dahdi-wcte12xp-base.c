--- freebsd/drivers/dahdi/wcte12xp/base.c.orig	2010-09-02 16:16:05.000000000 +0700
+++ freebsd/drivers/dahdi/wcte12xp/base.c	2013-10-31 18:13:29.000000000 +0700
@@ -1626,7 +1626,11 @@
 
 	t4_serial_setup(wc);
 
+#if defined(__FreeBSD__)
+	num = device_get_unit(pdev->dev) + 1;
+#else
 	num = x;
+#endif
 	sprintf(wc->span.name, "WCT1/%d", num);
 	snprintf(wc->span.desc, sizeof(wc->span.desc) - 1, "%s Card %d", wc->variety, num);
 	wc->span.manufacturer = "Digium";
