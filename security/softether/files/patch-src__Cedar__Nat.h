--- src/Cedar/Nat.h.orig	2014-06-08 06:19:15 UTC
+++ src/Cedar/Nat.h
@@ -115,7 +115,7 @@
 #define	NAT_H
 
 // Constants
-#define	NAT_CONFIG_FILE_NAME			"@vpn_router.config"	// NAT configuration file
+#define	NAT_CONFIG_FILE_NAME			"/var/db/softether/vpn_router.config"	// NAT configuration file
 #define	DEFAULT_NAT_ADMIN_PORT			2828		// Default port number for management
 #define	NAT_ADMIN_PORT_LISTEN_INTERVAL	1000		// Interval for trying to open a port for management
 #define	NAT_FILE_SAVE_INTERVAL			(30 * 1000)	// Interval to save
