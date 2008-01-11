Index: snmplib/snmpTCPIPv6Domain.c
diff -u -p snmplib/snmpTCPIPv6Domain.c.orig snmplib/snmpTCPIPv6Domain.c
--- snmplib/snmpTCPIPv6Domain.c.orig	Fri Sep 16 19:30:49 2005
+++ snmplib/snmpTCPIPv6Domain.c	Fri Jan 11 13:40:09 2008
@@ -96,13 +96,24 @@ netsnmp_tcp6_fmtaddr(netsnmp_transport *
     if (to == NULL) {
         return strdup("TCP/IPv6: unknown");
     } else {
-        char addr[INET6_ADDRSTRLEN];
-        char tmp[INET6_ADDRSTRLEN + 8];
+	char addr[NI_MAXHOST], tmp[NI_MAXHOST + NI_MAXSERV + 12];
 
-        sprintf(tmp, "TCP/IPv6: [%s]:%hd",
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
+	snprintf(tmp, sizeof(tmp), "TCP/IPv6: [%s]:%hd", addr,
+		 ntohs(to->sin6_port));
+	return strdup(tmp);
     }
 }
 
