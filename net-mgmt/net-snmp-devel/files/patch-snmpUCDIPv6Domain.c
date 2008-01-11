Index: snmplib/snmpUDPIPv6Domain.c
diff -u -p snmplib/snmpUDPIPv6Domain.c.orig snmplib/snmpUDPIPv6Domain.c
--- snmplib/snmpUDPIPv6Domain.c.orig	Mon Aug 20 17:06:42 2007
+++ snmplib/snmpUDPIPv6Domain.c	Fri Jan 11 13:39:36 2008
@@ -103,13 +103,24 @@ netsnmp_udp6_fmtaddr(netsnmp_transport *
     if (to == NULL) {
         return strdup("UDP/IPv6: unknown");
     } else {
-        char addr[INET6_ADDRSTRLEN];
-        char tmp[INET6_ADDRSTRLEN + 18];
+	char addr[NI_MAXHOST], tmp[NI_MAXHOST + NI_MAXSERV + 12];
 
-        sprintf(tmp, "UDP/IPv6: [%s]:%hu",
-                inet_ntop(AF_INET6, (void *) &(to->sin6_addr), addr,
-                          INET6_ADDRSTRLEN), ntohs(to->sin6_port));
-        return strdup(tmp);
+/*
+ * NI_WITHSCOPEID will be obsoleted.  But some implementations require
+ * this flag to retrieve scoped name.
+ * (2002-07-25: kuriyama@FreeBSD.org)
+ */
+#ifndef NI_WITHSCOPEID
+#define NI_WITHSCOPEID 0
+#endif
+	if (getnameinfo((struct sockaddr *)to, sizeof(struct sockaddr_in6),
+			addr, sizeof(addr), NULL, 0,
+			NI_NUMERICHOST | NI_WITHSCOPEID)) {
+	    return strdup("UDP/IPv6: unknown");
+	}
+	snprintf(tmp, sizeof(tmp), "UDP/IPv6: [%s]:%hu", addr,
+		 ntohs(to->sin6_port));
+	return strdup(tmp);
     }
 }
 
