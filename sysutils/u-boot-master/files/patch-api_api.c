--- api/api.c.orig	2018-01-09 01:25:29 UTC
+++ api/api.c
@@ -290,6 +290,11 @@ static int API_dev_close(va_list ap)
 	if (!err)
 		di->state = DEV_STA_CLOSED;
 
+	if (dcache_status())
+		flush_dcache_all();
+	if (icache_status())
+		invalidate_icache_all();
+
 	return err;
 }
 
