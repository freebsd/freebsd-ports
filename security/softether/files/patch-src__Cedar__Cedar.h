--- src/Cedar/Cedar.h.orig	2014-06-08 06:19:15 UTC
+++ src/Cedar/Cedar.h
@@ -477,22 +477,22 @@
 #define	LOG_ENGINE_BUFFER_CACHE_SIZE_MAX	(10 * 1024 * 1024)	// Write cache size
 
 // Constant such as a file name
-#define	SERVER_LOG_DIR_NAME			"@server_log"
+#define	SERVER_LOG_DIR_NAME			"/var/db/softether/server_log"
 #define	BRIDGE_LOG_DIR_NAME			SERVER_LOG_DIR_NAME
 #define	SERVER_LOG_PERFIX			"vpn"
 
-#define	HUB_SECURITY_LOG_DIR_NAME	"@security_log"
-#define	HUB_SECURITY_LOG_FILE_NAME	"@security_log/%s"
+#define	HUB_SECURITY_LOG_DIR_NAME	"/var/db/softether/security_log"
+#define	HUB_SECURITY_LOG_FILE_NAME	"/var/db/softether/security_log/%s"
 #define	HUB_SECURITY_LOG_PREFIX		"sec"
-#define	HUB_PACKET_LOG_DIR_NAME		"@packet_log"
-#define	HUB_PACKET_LOG_FILE_NAME	"@packet_log/%s"
+#define	HUB_PACKET_LOG_DIR_NAME		"/var/db/softether/packet_log"
+#define	HUB_PACKET_LOG_FILE_NAME	"/var/db/softether/packet_log/%s"
 #define	HUB_PACKET_LOG_PREFIX		"pkt"
 
-#define	NAT_LOG_DIR_NAME			"@secure_nat_log"
-#define	NAT_LOG_FILE_NAME			"@secure_nat_log/%s"
+#define	NAT_LOG_DIR_NAME			"/var/db/softether/secure_nat_log"
+#define	NAT_LOG_FILE_NAME			"/var/db/softether/secure_nat_log/%s"
 #define	NAT_LOG_PREFIX				"snat"
 
-#define	CLIENT_LOG_DIR_NAME			"@client_log"
+#define	CLIENT_LOG_DIR_NAME			"/var/db/softether/client_log"
 #define	CLIENT_LOG_PREFIX			"client"
 
 // Packet log settings
@@ -527,8 +527,8 @@
 #define	DISK_FREE_CHECK_INTERVAL	(5 * 60 * 1000)
 
 // Simple log
-#define TINY_LOG_DIRNAME			"@tiny_log"
-#define TINY_LOG_FILENAME			"@tiny_log/%04u%02u%02u_%02u%02u%02u.log"
+#define TINY_LOG_DIRNAME			"/var/db/softether/tiny_log"
+#define TINY_LOG_FILENAME			"/var/db/softether/tiny_log/%04u%02u%02u_%02u%02u%02u.log"
 
 
 //////////////////////////////////////////////////////////////////////
@@ -541,7 +541,7 @@
 //#define CE_SNAPSHOT_INTERVAL		((UINT64)(3000))
 #define CE_SNAPSHOT_POLLING_INTERVAL	(1 * 1000)
 #define CE_SNAPSHOT_POLLING_INTERVAL_LICENSE	(30 * 1000)
-#define CE_SNAPSHOT_DIR_NAME		"@carrier_log"
+#define CE_SNAPSHOT_DIR_NAME		"/var/db/softether/carrier_log"
 #define CE_SNAPSHOT_PREFIX			"carrier"
 
 
@@ -558,7 +558,7 @@
 // Expiration date of random size cache
 #define	RAND_SIZE_CACHE_EXPIRE		(24 * 60 * 60 * 1000)
 // Management allowed IP address list file name
-#define	ADMINIP_TXT					"@adminip.txt"
+#define	ADMINIP_TXT					"/var/db/softether/adminip.txt"
 
 #define NON_SSL_MIN_COUNT			60
 #define NON_SSL_ENTRY_EXPIRES		(10 * 60 * 1000)
@@ -609,9 +609,9 @@
 //////////////////////////////////////////////////////////////////////
 
 #define	EL_ADMIN_PORT			22888
-#define	EL_CONFIG_FILENAME		"@etherlogger.config"
-#define	EL_PACKET_LOG_DIR_NAME	"@etherlogger_log"
-#define	EL_PACKET_LOG_FILE_NAME	"@etherlogger_log/%s"
+#define	EL_CONFIG_FILENAME		"/var/db/softether/etherlogger.config"
+#define	EL_PACKET_LOG_DIR_NAME	"/var/db/softether/etherlogger_log"
+#define	EL_PACKET_LOG_FILE_NAME	"/var/db/softether/etherlogger_log/%s"
 #define	EL_PACKET_LOG_PREFIX	"pkt"
 #define	EL_LICENSE_CHECK_SPAN	(10 * 1000)
 
