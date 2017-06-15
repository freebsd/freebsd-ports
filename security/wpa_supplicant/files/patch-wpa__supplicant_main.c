--- wpa_supplicant/main.c.orig	2016-11-05 20:56:30 UTC
+++ wpa_supplicant/main.c
@@ -66,7 +66,7 @@ static void usage(void)
 	       "  -c = Configuration file\n"
 	       "  -C = ctrl_interface parameter (only used if -c is not)\n"
 	       "  -d = increase debugging verbosity (-dd even more)\n"
-	       "  -D = driver name (can be multiple drivers: nl80211,wext)\n"
+	       "  -D = driver name (can be multiple drivers: bsd,wired)\n"
 	       "  -e = entropy file\n"
 #ifdef CONFIG_DEBUG_FILE
 	       "  -f = log output to debug file instead of stdout\n"
@@ -105,8 +105,7 @@ static void usage(void)
 	       "  -W = wait for a control interface monitor before starting\n");
 
 	printf("example:\n"
-	       "  wpa_supplicant -D%s -iwlan0 -c/etc/wpa_supplicant.conf\n",
-	       wpa_drivers[0] ? wpa_drivers[0]->name : "nl80211");
+                "  wpa_supplicant -Dbsd -iwlan0 -c/etc/wpa_supplicant.conf\n");
 #endif /* CONFIG_NO_STDOUT_DEBUG */
 }
 
@@ -199,6 +198,11 @@ int main(int argc, char *argv[])
 
 	wpa_supplicant_fd_workaround(1);
 
+#ifdef CONFIG_DRIVER_NDIS
+	void driver_ndis_init_ops(void);
+	driver_ndis_init_ops();
+#endif /* CONFIG_DRIVER_NDIS */
+
 	for (;;) {
 		c = getopt(argc, argv,
 			   "b:Bc:C:D:de:f:g:G:hi:I:KLMm:No:O:p:P:qsTtuvW");
