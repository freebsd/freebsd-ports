
$FreeBSD$

--- src/include/gnunet_util.h.orig
+++ src/include/gnunet_util.h
@@ -637,7 +637,7 @@
  * Default names of the configuration files.
  */
 #define DEFAULT_CLIENT_CONFIG_FILE "~/.gnunet/gnunet.conf"
-#define DEFAULT_DAEMON_CONFIG_FILE "/etc/gnunet.conf"
+#define DEFAULT_DAEMON_CONFIG_FILE "%%PREFIX%%/etc/gnunet.conf"
 
 /* *******************API *********************** */
 
@@ -1053,8 +1053,8 @@
  * @param ip the IP to check (in network byte order)
  * @return NO if the IP is not in the list, YES if it it is
  */
-int checkIP6Listed(const CIDR6Network * list,
-		   const IP6addr * ip);
+int checkIP6Listed(CIDR6Network * list,
+		   IP6addr * ip);
 
 /**
  * Parse a network specification. The argument specifies
