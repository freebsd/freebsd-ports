--- lib/uuid/gen_uuid.c.orig	2018-03-25 02:42:47 UTC
+++ lib/uuid/gen_uuid.c
@@ -94,6 +94,7 @@
 #ifdef HAVE_SYS_RESOURCE_H
 #include <sys/resource.h>
 #endif
+#include <ifaddrs.h>
 
 #include "uuidP.h"
 #include "uuidd.h"
@@ -300,6 +301,28 @@ static int get_node_id(unsigned char *no
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
@@ -408,7 +431,7 @@ try_again:
 		rewind(state_f);
 		len = fprintf(state_f,
 			      "clock: %04x tv: %016lu %08lu adj: %08d\n",
-			      clock_seq, last.tv_sec, (long)last.tv_usec,
+			      clock_seq, (unsigned long)last.tv_sec, (unsigned long)last.tv_usec,
 			      adjustment);
 		fflush(state_f);
 		if (ftruncate(state_fd, len) < 0) {
