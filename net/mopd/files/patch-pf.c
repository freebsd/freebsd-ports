--- common/pf.c.orig	Tue Aug  6 07:20:27 1996
+++ common/pf.c	Wed Oct 15 13:02:19 2003
@@ -56,7 +56,7 @@
 #include <strings.h>
 
 #include <syslog.h>
-#include <varargs.h>
+
 
 #include "common/mopdef.h"
 
@@ -174,7 +174,8 @@
 	struct ifreq ifr;
 	int	fd;
 	
-	strcpy(ifr.ifr_name, interface);
+	strncpy(ifr.ifr_name, interface,sizeof(ifr.ifr_name) - 1);
+	ifr.ifr_name[sizeof(ifr.ifr_name) - 1] = 0;
 
 	ifr.ifr_addr.sa_family = AF_UNSPEC;
 	bcopy(addr, ifr.ifr_addr.sa_data, 6);
@@ -209,7 +210,8 @@
 	struct ifreq ifr;
 	int	fd;
 	
-	strcpy(ifr.ifr_name, interface);
+	strncpy(ifr.ifr_name, interface, sizeof (ifr.ifr_name) - 1);
+	ifr.ifr_name[sizeof(ifr.ifr_name) - 1] = 0;
 	
 	ifr.ifr_addr.sa_family = AF_UNSPEC;
 	bcopy(addr, ifr.ifr_addr.sa_data, 6);
