--- config.h.orig       Mon Jun  2 22:04:52 2003
+++ config.h    Mon Jun  2 22:05:03 2003
@@ -35,7 +35,7 @@
 /* We assume that systems which don't have IPv6
    headers don't have ntop and pton either */
 
-#if defined(INET6_ADDRSTRLEN)
+#if defined(INET6_ADDRSTRLEN) && defined(WITH_IPV6)
 #  define HAVE_IPV6
 #  define ADDRSTRLEN INET6_ADDRSTRLEN
 #elif defined(INET_ADDRSTRLEN)

