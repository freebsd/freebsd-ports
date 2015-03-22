--- wpa_supplicant/wpa_supplicant.c.orig	2015-03-15 17:30:39 UTC
+++ wpa_supplicant/wpa_supplicant.c
@@ -4506,7 +4506,7 @@ struct wpa_global * wpa_supplicant_init(
 	if (params == NULL)
 		return NULL;
 
-#ifdef CONFIG_DRIVER_NDIS
+#ifdef XXXCONFIG_DRIVER_NDIS
 	{
 		void driver_ndis_init_ops(void);
 		driver_ndis_init_ops();
