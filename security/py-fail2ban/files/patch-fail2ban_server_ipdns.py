--- fail2ban/server/ipdns.py.orig	2017-08-09 14:53:05 UTC
+++ fail2ban/server/ipdns.py
@@ -69,10 +69,14 @@ class DNSUtils:
 		for fam, ipfam in ((socket.AF_INET, IPAddr.FAM_IPv4), (socket.AF_INET6, IPAddr.FAM_IPv6)):
 			try:
 				for result in socket.getaddrinfo(dns, None, fam, 0, socket.IPPROTO_TCP):
-					ip = IPAddr(result[4][0], ipfam)
+					# if getaddrinfo returns something unexpected:
+					if len(result) < 4 or not len(result[4]): continue
+					# be sure we have an ip-string
+					# some return an integer there
+					ip = IPAddr(str(result[4][0]), ipfam)
 					if ip.isValid:
 						ips.append(ip)
-			except socket.error as e:
+			except Exception as e:
 				saveerr = e
 		if not ips and saveerr:
 			logSys.warning("Unable to find a corresponding IP address for %s: %s", dns, saveerr)
