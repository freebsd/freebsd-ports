--- common/pf.c.orig	1996-08-06 14:20:27 UTC
+++ common/pf.c
@@ -56,8 +56,8 @@ static char rcsid[] = "$Id: pf.c,v 1.16 1996/08/06 14:
 #include <strings.h>
 
 #include <syslog.h>
-#include <varargs.h>
 
+
 #include "common/mopdef.h"
 
 /*
@@ -174,7 +174,8 @@ pfAddMulti(s, interface, addr)
 	struct ifreq ifr;
 	int	fd;
 	
-	strcpy(ifr.ifr_name, interface);
+	strncpy(ifr.ifr_name, interface,sizeof(ifr.ifr_name) - 1);
+	ifr.ifr_name[sizeof(ifr.ifr_name) - 1] = 0;
 
 	ifr.ifr_addr.sa_family = AF_UNSPEC;
 	bcopy(addr, ifr.ifr_addr.sa_data, 6);
@@ -209,7 +210,8 @@ pfDelMulti(s, interface, addr)
 	struct ifreq ifr;
 	int	fd;
 	
-	strcpy(ifr.ifr_name, interface);
+	strncpy(ifr.ifr_name, interface, sizeof (ifr.ifr_name) - 1);
+	ifr.ifr_name[sizeof(ifr.ifr_name) - 1] = 0;
 	
 	ifr.ifr_addr.sa_family = AF_UNSPEC;
 	bcopy(addr, ifr.ifr_addr.sa_data, 6);
