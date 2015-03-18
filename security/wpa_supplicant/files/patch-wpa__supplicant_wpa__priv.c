--- wpa_supplicant/wpa_priv.c.orig	2015-03-15 17:30:39 UTC
+++ wpa_supplicant/wpa_priv.c
@@ -952,6 +952,7 @@ static void usage(void)
 int main(int argc, char *argv[])
 {
 	int c, i;
+	int eloop_initialized = 0;
 	int ret = -1;
 	char *pid_file = NULL;
 	int daemonize = 0;
@@ -997,6 +998,7 @@ int main(int argc, char *argv[])
 		wpa_printf(MSG_ERROR, "Failed to initialize event loop");
 		goto out;
 	}
+	else eloop_initialized = 1;
 
 	for (i = optind; i < argc; i++) {
 		wpa_printf(MSG_DEBUG, "Adding driver:interface %s", argv[i]);
@@ -1023,7 +1025,8 @@ out:
 		wpa_priv_interface_deinit(prev);
 	}
 
-	eloop_destroy();
+	if (eloop_initialized)
+		eloop_destroy();
 
 	os_daemonize_terminate(pid_file);
 	os_free(pid_file);
