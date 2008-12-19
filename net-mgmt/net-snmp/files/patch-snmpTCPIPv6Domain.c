--- snmplib/snmpTCPIPv6Domain.c.orig	2008-06-17 17:57:14.000000000 +0900
+++ snmplib/snmpTCPIPv6Domain.c	2008-11-14 21:34:12.000000000 +0900
@@ -96,12 +96,23 @@
     if (to == NULL) {
         return strdup("TCP/IPv6: unknown");
     } else {
-        char addr[INET6_ADDRSTRLEN];
-        char tmp[INET6_ADDRSTRLEN + 18];
+        char addr[NI_MAXHOST], tmp[NI_MAXHOST + NI_MAXSERV + 12];
 
-        sprintf(tmp, "TCP/IPv6: [%s]:%hd",
-                inet_ntop(AF_INET6, (void *) &(to->sin6_addr), addr,
-                          INET6_ADDRSTRLEN), ntohs(to->sin6_port));
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
         return strdup(tmp);
     }
 }
