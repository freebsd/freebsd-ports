# Use correct width in sscanf. Fixes #1156
# https://github.com/nmap/nmap/commit/36a6d897a584013d25e51ac339fe45ffc45df9df

--- libdnet-stripped/src/arp-ioctl.c.orig	2008-09-19 06:12:25 UTC
+++ libdnet-stripped/src/arp-ioctl.c
@@ -218,7 +218,7 @@ arp_loop(arp_t *a, arp_handler callback,
 
 	ret = 0;
 	while (fgets(buf, sizeof(buf), fp) != NULL) {
-		i = sscanf(buf, "%s 0x%x 0x%x %100s %100s %100s\n",
+		i = sscanf(buf, "%s 0x%x 0x%x %99s %99s %99s\n",
 		    ipbuf, &type, &flags, macbuf, maskbuf, devbuf);
 		
 		if (i < 4 || (flags & ATF_COM) == 0)
