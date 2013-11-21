
$FreeBSD$

--- tun.cpp.orig
+++ tun.cpp
@@ -41,8 +41,7 @@
 
 	if (device != NULL)
 	{
-		strncpy(this->device, device, VTUN_DEV_LEN);
-		this->device[VTUN_DEV_LEN] = 0;
+		strlcpy(this->device, device, VTUN_DEV_LEN);
 	}
 	else
 		this->device[0] = 0;
@@ -68,23 +67,17 @@
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
