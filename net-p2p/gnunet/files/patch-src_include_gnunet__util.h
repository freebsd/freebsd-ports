
$FreeBSD$

--- src/include/gnunet_util.h.orig	Tue Aug 24 17:58:14 2004
+++ src/include/gnunet_util.h	Sat Oct  2 23:25:56 2004
@@ -628,7 +628,7 @@
  * Default names of the configuration files.
  */
 #define DEFAULT_CLIENT_CONFIG_FILE "~/.gnunet/gnunet.conf"
-#define DEFAULT_DAEMON_CONFIG_FILE "/etc/gnunet.conf"
+#define DEFAULT_DAEMON_CONFIG_FILE "%%PREFIX%%/etc/gnunet.conf"
 
 /* *******************API *********************** */
 
@@ -1027,8 +1027,8 @@
  * @param ip the IP to check (in network byte order)
  * @return NO if the IP is not in the list, YES if it it is
  */
-int checkIP6Listed(const CIDR6Network * list,
-		   const IP6addr * ip);
+int checkIP6Listed(CIDR6Network * list,
+		   IP6addr * ip);
 
 /**
  * Parse a network specification. The argument specifies
@@ -1041,7 +1041,7 @@
  * @param routeList a string specifying the forbidden networks
  * @return the converted list, NULL if the synatx is flawed
  */
-CIDR6Network * parseRoutes6(const char * routeList);
+CIDR6Network * parseRoutes6(char * routeList);
 
 
 
