--- src/Cedar/Client.h.orig	2016-05-03 06:16:53 UTC
+++ src/Cedar/Client.h
@@ -125,7 +125,7 @@
 
 
 // Constants
-#define	CLIENT_CONFIG_FILE_NAME				"@vpn_client.config"
+#define	CLIENT_CONFIG_FILE_NAME				"/var/db/softether/vpn_client.config"
 #define	CLIENT_DEFAULT_KEEPALIVE_HOST		"keepalive.softether.org"
 #define	CLIENT_DEFAULT_KEEPALIVE_PORT		80
 #define	CLIENT_DEFAULT_KEEPALIVE_INTERVAL	KEEP_INTERVAL_DEFAULT
@@ -145,7 +145,7 @@
 #define	CLIENT_WIN32_EXE_FILENAME_X64		"vpnclient_x64.exe"
 #define	CLIENT_WIN32_EXE_FILENAME_IA64		"vpnclient_ia64.exe"
 
-#define CLIENT_CUSTOM_INI_FILENAME			"@custom.ini"
+#define CLIENT_CUSTOM_INI_FILENAME			"/var/db/softether/custom.ini"
 
 #define	CLIENT_GLOBAL_PULSE_NAME			"clientglobalpulse"
 
