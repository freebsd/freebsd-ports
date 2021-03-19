--- wpa_supplicant/wpa_supplicant.c.orig	2019-04-21 03:10:22.000000000 -0400
+++ wpa_supplicant/wpa_supplicant.c	2019-05-15 22:44:44.919859000 -0400
@@ -6357,13 +6357,6 @@
 	if (params == NULL)
 		return NULL;
 
-#ifdef CONFIG_DRIVER_NDIS
-	{
-		void driver_ndis_init_ops(void);
-		driver_ndis_init_ops();
-	}
-#endif /* CONFIG_DRIVER_NDIS */
-
 #ifndef CONFIG_NO_WPA_MSG
 	wpa_msg_register_ifname_cb(wpa_supplicant_msg_ifname_cb);
 #endif /* CONFIG_NO_WPA_MSG */
