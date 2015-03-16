--- src/drivers/driver_ndis.c.orig	2015-03-15 17:30:39 UTC
+++ src/drivers/driver_ndis.c
@@ -2110,7 +2110,11 @@ static int wpa_driver_ndis_get_names(str
 		dlen = dpos - desc;
 	else
 		dlen = os_strlen(desc);
-	drv->adapter_desc = dup_binstr(desc, dlen);
+	drv->adapter_desc = os_malloc(dlen + 1);
+	if (drv->adapter_desc) {
+		os_memcpy(drv->adapter_desc, desc, dlen);
+		drv->adapter_desc[dlen] = '\0';
+	}
 	os_free(b);
 	if (drv->adapter_desc == NULL)
 		return -1;
@@ -2278,7 +2282,11 @@ static int wpa_driver_ndis_get_names(str
 	} else {
 		dlen = os_strlen(desc[i]);
 	}
-	drv->adapter_desc = dup_binstr(desc[i], dlen);
+	drv->adapter_desc = os_malloc(dlen + 1);
+	if (drv->adapter_desc) {
+		os_memcpy(drv->adapter_desc, desc[i], dlen);
+		drv->adapter_desc[dlen] = '\0';
+	}
 	os_free(names);
 	if (drv->adapter_desc == NULL)
 		return -1;
