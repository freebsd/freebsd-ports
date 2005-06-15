--- src/popd.c.orig	Wed Jun 15 15:28:13 2005
+++ src/popd.c	Wed Jun 15 15:49:05 2005
@@ -46,6 +46,7 @@
 #include <unistd.h>
 
 #include <poputil.h>
+#include <osreldate.h>
 #include "config.h"
 #include "popd.h"
 #include "paths.h"
@@ -280,9 +281,15 @@
 			}
 #endif
 			if (bind(serverfd, r->ai_addr, r->ai_addrlen) < 0) {
+#if __FreeBSD_version >= 502000
+				getnameinfo(r->ai_addr, r->ai_addrlen,
+                                            ip, sizeof(ip), NULL, 0,
+                                            NI_NUMERICHOST);
+#else
 				getnameinfo(r->ai_addr, r->ai_addrlen,
 					    ip, sizeof(ip), NULL, 0,
 					    NI_NUMERICHOST | NI_WITHSCOPEID);
+#endif
 				syslog(facility, "Can't bind port %s on %s",
 				       config.port, ip);
 				close(serverfd);
@@ -434,8 +441,13 @@
 	facility = LOG_INFO;
 	if (config.daemonise || config.debug)
 #ifdef USE_IPV6
+#if __FreeBSD_version >= 502000
+		getnameinfo((struct sockaddr *)&addr, addr.ss_len,
+		    ip, sizeof(ip), NULL, 0, NI_NUMERICHOST);
+#else
 		getnameinfo((struct sockaddr *)&addr, addr.ss_len,
 		    ip, sizeof(ip), NULL, 0, NI_NUMERICHOST | NI_WITHSCOPEID);
+#endif
 	if (config.daemonise || config.debug)
 		syslog(facility, "Connection from %s", ip);
 #else
