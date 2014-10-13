--- wpa_supplicant/wpa_supplicant.c.orig	2014-10-09 14:41:31 UTC
+++ wpa_supplicant/wpa_supplicant.c
@@ -4098,7 +4098,7 @@ struct wpa_global * wpa_supplicant_init(
 	if (params == NULL)
 		return NULL;
 
-#ifdef CONFIG_DRIVER_NDIS
+#ifdef XXXCONFIG_DRIVER_NDIS
 	{
 		void driver_ndis_init_ops(void);
 		driver_ndis_init_ops();
