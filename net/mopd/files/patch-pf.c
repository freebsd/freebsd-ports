--- common/pf.c	1997/08/18 03:11:31	1.3
+++ common/pf.c	2000/02/20 17:45:33	1.4
@@ -176,7 +176,8 @@
 	struct ifreq ifr;
 	int	fd;
 	
-	strcpy(ifr.ifr_name, interface);
+	strncpy(ifr.ifr_name, interface,sizeof(ifr.ifr_name) - 1);
+	ifr.ifr_name[sizeof(ifr.ifr_name) - 1] = 0;
 
 	ifr.ifr_addr.sa_family = AF_UNSPEC;
 	bcopy(addr, ifr.ifr_addr.sa_data, 6);
@@ -211,7 +212,8 @@
 	struct ifreq ifr;
 	int	fd;
 	
-	strcpy(ifr.ifr_name, interface);
+	strncpy(ifr.ifr_name, interface, sizeof (ifr.ifr_name) - 1);
+	ifr.ifr_name[sizeof(ifr.ifr_name) - 1] = 0;
 	
 	ifr.ifr_addr.sa_family = AF_UNSPEC;
 	bcopy(addr, ifr.ifr_addr.sa_data, 6);
