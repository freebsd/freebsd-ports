--- src/dot1ag_eth.c.orig	2012-09-20 12:44:39 UTC
+++ src/dot1ag_eth.c
@@ -78,7 +78,7 @@ get_local_mac(char *dev, uint8_t *ea) {
 		if (ifa->ifa_addr == NULL) {
 			continue;
 		}
-		if (strncmp(ifa->ifa_name, dev, sizeof(dev)) != 0) {
+		if (strcmp(ifa->ifa_name, dev) != 0) {
 			continue;  /* not the interface we are looking for */
 		}
 		sdl = (struct sockaddr_dl *) ifa->ifa_addr;
