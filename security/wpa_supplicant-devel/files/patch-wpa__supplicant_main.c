--- wpa_supplicant/main.c.orig	2025-11-07 07:33:18.000000000 -0800
+++ wpa_supplicant/main.c	2025-11-17 09:07:02.682216000 -0800
@@ -67,7 +67,7 @@
 	       "  -c = Configuration file\n"
 	       "  -C = ctrl_interface parameter (only used if -c is not)\n"
 	       "  -d = increase debugging verbosity (-dd even more)\n"
-	       "  -D = driver name (can be multiple drivers: nl80211,wext)\n"
+	       "  -D = driver name (can be multiple drivers: bsd,wired)\n"
 	       "  -e = entropy file\n"
 #ifdef CONFIG_DEBUG_FILE
 	       "  -f = log output to debug file instead of stdout\n"
@@ -107,8 +107,7 @@
 	       "  -y = show configuration parsing details in debug log\n");
 
 	printf("example:\n"
-	       "  wpa_supplicant -D%s -iwlan0 -c/etc/wpa_supplicant.conf\n",
-	       wpa_drivers[0] ? wpa_drivers[0]->name : "nl80211");
+	       "  wpa_supplicant -Dbsd -iwlan0 -c/etc/wpa_supplicant.conf\n");
 	printf("\nIf run without specifying a network interface or control interface, the a\n"
 	       "configuration file is parsed without starting any operation.\n"
 		"This can be used to check whether a configuration file has valid contents.\n");
@@ -204,6 +203,11 @@
 
 	wpa_supplicant_fd_workaround(1);
 
+#ifdef CONFIG_DRIVER_NDIS
+	void driver_ndis_init_ops(void);
+	driver_ndis_init_ops();
+#endif /* CONFIG_DRIVER_NDIS */
+
 	for (;;) {
 		c = getopt(argc, argv,
 			   "b:Bc:C:D:de:f:g:G:hi:I:KLMm:No:O:p:P:qsTtuvWy");
