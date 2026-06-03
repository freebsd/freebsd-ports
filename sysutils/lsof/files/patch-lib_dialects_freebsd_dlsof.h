--- lib/dialects/freebsd/dlsof.h.orig	2026-03-25 16:34:30 UTC
+++ lib/dialects/freebsd/dlsof.h
@@ -147,6 +147,7 @@ int getmntinfo(struct statfs **, int);
 #    include <netinet/ip.h>
 #    include <net/route.h>
 #    define _WANT_INPCB /* for FreeBSD 12 and above */
+#    include <sys/ck.h>
 #    include <netinet/in_pcb.h>
 #    include <netinet/ip_var.h>
 #    include <netinet/tcp.h>
