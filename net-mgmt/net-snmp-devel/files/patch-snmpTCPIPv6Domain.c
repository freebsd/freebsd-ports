--- snmplib/snmpTCPIPv6Domain.c.orig	Sat Oct 16 03:52:29 2004
+++ snmplib/snmpTCPIPv6Domain.c	Mon Oct 25 09:22:06 2004
@@ -95,13 +95,21 @@
     if (to == NULL) {
         return strdup("TCP/IPv6: unknown");
     } else {
-        char addr[INET6_ADDRSTRLEN];
-        char tmp[INET6_ADDRSTRLEN + 8];
+        char tmp[NI_MAXHOST];
 
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
+	if (getnameinfo(to, sizeof(struct sockaddr_in6), tmp, sizeof(tmp),
+			NULL, 0, NI_NUMERICHOST | NI_WITHSCOPEID)) {
+	    return strdup("UDP/IPv6: unknown");
+	}
+	return strdup(tmp);
     }
 }
 
