--- api/api.c.orig	2018-07-09 14:24:14 UTC
+++ api/api.c
@@ -289,6 +289,11 @@ static int API_dev_close(va_list ap)
 	if (!err)
 		di->state = DEV_STA_CLOSED;
 
+	if (dcache_status())
+		flush_dcache_all();
+	if (icache_status())
+		invalidate_icache_all();
+
 	return err;
 }
 
