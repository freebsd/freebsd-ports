--- m4/nut_check_ipv6.m4.orig	2007-03-15 21:19:05.000000000 +0100
+++ m4/nut_check_ipv6.m4	2007-10-15 11:42:02.000000000 +0200
@@ -22,7 +22,9 @@
 		   struct in6_addr],
                   [:],
                   [nut_have_ipv6=no],
-		  [#include <netdb.h>])
+		  [#include <netdb.h>
+		   #include <sys/socket.h>
+		   #include <netinet/in.h>])
 
 dnl AC_CHECK_MEMBERS([struct in6_addr.s6_addr32],
 dnl               [:],
