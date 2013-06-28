--- tun.cpp.orig	2010-02-17 17:30:21.000000000 +0200
+++ tun.cpp	2013-04-04 16:55:39.802818893 +0300
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
