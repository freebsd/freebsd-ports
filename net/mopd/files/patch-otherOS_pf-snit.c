--- otherOS/pf-snit.c.orig	1996-08-08 11:48:50 UTC
+++ otherOS/pf-snit.c
@@ -237,7 +237,8 @@ pfAddMulti(s, interface, addr)
 	struct ifreq ifr;
 	int fd;
 	
-	strcpy(ifr.ifr_name, interface);
+	strncpy(ifr.ifr_name, interface, sizeof (ifr.ifr_name) -1);
+	ifr.ifr_name[sizeof(ifr.ifr_name) - 1] = 0;
 	
 	ifr.ifr_addr.sa_family = AF_UNSPEC;
 	bcopy(addr, ifr.ifr_addr.sa_data, 6);
@@ -272,7 +273,8 @@ char *interface, *addr;
 	struct ifreq ifr;
 	int fd;
 	
-	strcpy(ifr.ifr_name, interface);
+	strncpy(ifr.ifr_name, interface, sizeof (ifr.ifr_name) -1);
+	ifr.ifr_name[sizeof(ifr.ifr_name) - 1] = 0;
 	
 	ifr.ifr_addr.sa_family = AF_UNSPEC;
 	bcopy(addr, ifr.ifr_addr.sa_data, 6);
