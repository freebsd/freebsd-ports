--- otherOS/pf-snit.c	1996/09/21 19:12:50	1.2
+++ otherOS/pf-snit.c	2000/02/20 17:45:34	1.3
@@ -239,7 +239,8 @@
 	struct ifreq ifr;
 	int fd;
 	
-	strcpy(ifr.ifr_name, interface);
+	strncpy(ifr.ifr_name, interface, sizeof (ifr.ifr_name) -1);
+	ifr.ifr_name[sizeof(ifr.ifr_name) - 1] = 0;
 	
 	ifr.ifr_addr.sa_family = AF_UNSPEC;
 	bcopy(addr, ifr.ifr_addr.sa_data, 6);
@@ -274,7 +275,8 @@
 	struct ifreq ifr;
 	int fd;
 	
-	strcpy(ifr.ifr_name, interface);
+	strncpy(ifr.ifr_name, interface, sizeof (ifr.ifr_name) -1);
+	ifr.ifr_name[sizeof(ifr.ifr_name) - 1] = 0;
 	
 	ifr.ifr_addr.sa_family = AF_UNSPEC;
 	bcopy(addr, ifr.ifr_addr.sa_data, 6);
