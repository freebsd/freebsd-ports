--- src/ipmievd.c.orig	2022-09-01 18:42:31 UTC
+++ src/ipmievd.c
@@ -55,7 +55,7 @@
 #endif
 
 #ifndef _PATH_RUN
-# define _PATH_RUN "/run/"
+# define _PATH_RUN "/var/run/"
 #endif
 
 #ifdef IPMI_INTF_OPEN
@@ -730,7 +730,7 @@ ipmievd_main(struct ipmi_event_intf * eintf, int argc,
 				return (-1);
 			}
 		}
-		else if (strcasecmp(argv[i], "pidfile=") == 0) {
+		else if (strncasecmp(argv[i], "pidfile=",8) == 0) {
 			memset(pidfile, 0, 64);
 			strncpy(pidfile, argv[i]+8,
 				__min(strlen((const char *)(argv[i]+8)), 63));
