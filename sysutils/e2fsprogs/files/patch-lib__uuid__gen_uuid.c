--- ./lib/uuid/gen_uuid.c.orig	2013-12-16 07:32:00.000000000 +0100
+++ ./lib/uuid/gen_uuid.c	2014-01-06 23:26:48.000000000 +0100
@@ -91,6 +91,7 @@
 #ifdef HAVE_SYS_RESOURCE_H
 #include <sys/resource.h>
 #endif
+#include <ifaddrs.h>
 
 #include "uuidP.h"
 #include "uuidd.h"
@@ -300,6 +301,28 @@
 		}
 	}
 	close(sd);
+#else
+	struct ifaddrs *ifaddrsp, *ifaddrp;
+	unsigned char 	*a;
+
+	if (getifaddrs(&ifaddrsp) < 0)
+		return -1;
+	for (ifaddrp = ifaddrsp; ifaddrp != NULL; ifaddrp = ifaddrp->ifa_next)
+	{
+		if (ifaddrp->ifa_addr == NULL)
+			continue;
+		if (ifaddrp->ifa_addr->sa_family != AF_LINK)
+			continue;
+		a = LLADDR((struct sockaddr_dl *)ifaddrp->ifa_addr);
+		if (!a[0] && !a[1] && !a[2] && !a[3] && !a[4] && !a[5])
+			continue;
+		if (node_id) {
+			memcpy(node_id, a, 6);
+			freeifaddrs(ifaddrsp);
+			return 1;
+		}
+	}
+	freeifaddrs(ifaddrsp);
 #endif
 	return 0;
 }
