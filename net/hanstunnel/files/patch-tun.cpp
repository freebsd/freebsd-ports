--- tun.cpp.orig	2010-02-17 10:30:21.000000000 -0500
+++ tun.cpp	2014-08-06 10:10:51.000000000 -0400
@@ -21,6 +21,7 @@
 #include "exception.h"
 #include "utility.h"
 
+#include <sys/types.h>
 #include <arpa/inet.h>
 #include <netinet/in_systm.h>
 #include <netinet/in.h>
@@ -41,8 +42,7 @@
 
 	if (device != NULL)
 	{
-		strncpy(this->device, device, VTUN_DEV_LEN);
-		this->device[VTUN_DEV_LEN] = 0;
+		strlcpy(this->device, device, VTUN_DEV_LEN);
 	}
 	else
 		this->device[0] = 0;
@@ -68,23 +68,17 @@
 	string ips = Utility::formatIp(ip);
 	string destIps = Utility::formatIp(destIp);
 
-#ifdef LINUX
-	snprintf(cmdline, sizeof(cmdline), "/sbin/ifconfig %s %s netmask 255.255.255.0", device, ips.c_str());
-#else
-	snprintf(cmdline, sizeof(cmdline), "/sbin/ifconfig %s %s %s netmask 255.255.255.255", device, ips.c_str(), destIps.c_str());
-#endif
+	snprintf(cmdline, sizeof(cmdline), "/sbin/ifconfig %s %s %s netmask 255.255.255.0", device, ips.c_str(), destIps.c_str());
 
 	if (system(cmdline) != 0)
 		syslog(LOG_ERR, "could not set tun device ip address");
 
-#ifndef LINUX
 	if (includeSubnet)
 	{
 		snprintf(cmdline, sizeof(cmdline), "/sbin/route add %s/24 %s", destIps.c_str(), destIps.c_str());
 		if (system(cmdline) != 0)
 			syslog(LOG_ERR, "could not add route");
 	}
-#endif
 }
 
 void Tun::write(const char *buffer, int length)
