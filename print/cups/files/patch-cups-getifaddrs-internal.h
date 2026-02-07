--- cups/getifaddrs-internal.h.orig	2020-04-27 18:04:29 UTC
+++ cups/getifaddrs-internal.h
@@ -39,6 +39,7 @@ typedef int socklen_t;
 
 #  ifndef _WIN32
 #    include <net/if.h>
+#    include <netinet/in.h>
 #    include <resolv.h>
 #    ifdef HAVE_GETIFADDRS
 #      include <ifaddrs.h>
