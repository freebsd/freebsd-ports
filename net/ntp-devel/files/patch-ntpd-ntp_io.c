--- ntpd/ntp_io.c.orig	2010-06-03 20:24:51.000000000 -0700
+++ ntpd/ntp_io.c	2010-06-03 20:27:36.000000000 -0700
@@ -1414,12 +1414,18 @@
 	sockaddr_u *psau
 	)
 {
+	unsigned char zerobuf[8];
+
 	if (IS_IPV4(psau) && !NSRCADR(psau))
 		return 1;
 
 #ifdef INCLUDE_IPV6_SUPPORT
 	if (IS_IPV6(psau) && S_ADDR6_EQ(psau, &in6addr_any))
 		return 1;
+	bzero(zerobuf, sizeof(zerobuf));
+	// If the host portion is all 0, then assume it's a router's anycast address.
+	if (IS_IPV6(psau) && memcmp((char*)(&((struct sockaddr_in6*)psau)->sin6_addr) + 8, zerobuf, 8) == 0)
+		return 1;
 #endif
 
 	return 0;
