--- wpa_supplicant/wpa_supplicant.c.orig	2024-07-20 18:04:37 UTC
+++ wpa_supplicant/wpa_supplicant.c
@@ -7983,13 +7983,6 @@ struct wpa_global * wpa_supplicant_init(struct wpa_par
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
