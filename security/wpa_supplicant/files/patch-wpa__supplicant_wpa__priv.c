--- wpa_supplicant/wpa_priv.c.orig	2014-10-09 14:41:31 UTC
+++ wpa_supplicant/wpa_priv.c
@@ -202,7 +202,7 @@ static void wpa_priv_cmd_associate(struc
 	if (assoc->ssid_len > 32)
 		return;
 	params.ssid_len = assoc->ssid_len;
-	params.freq = assoc->freq;
+	params.freq.freq = assoc->freq;
 	if (assoc->wpa_ie_len) {
 		params.wpa_ie = (u8 *) (assoc + 1);
 		params.wpa_ie_len = assoc->wpa_ie_len;
@@ -947,6 +947,7 @@ static void usage(void)
 int main(int argc, char *argv[])
 {
 	int c, i;
+	int eloop_initialized = 0;
 	int ret = -1;
 	char *pid_file = NULL;
 	int daemonize = 0;
@@ -992,6 +993,7 @@ int main(int argc, char *argv[])
 		wpa_printf(MSG_ERROR, "Failed to initialize event loop");
 		goto out;
 	}
+	else eloop_initialized = 1;
 
 	for (i = optind; i < argc; i++) {
 		wpa_printf(MSG_DEBUG, "Adding driver:interface %s", argv[i]);
@@ -1018,7 +1020,8 @@ out:
 		wpa_priv_interface_deinit(prev);
 	}
 
-	eloop_destroy();
+	if (eloop_initialized)
+		eloop_destroy();
 
 	os_daemonize_terminate(pid_file);
 	os_free(pid_file);
