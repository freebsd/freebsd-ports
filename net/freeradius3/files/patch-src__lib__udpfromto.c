--- ./src/lib/udpfromto.c.orig	2014-03-21 08:27:25.000000000 -0400
+++ ./src/lib/udpfromto.c	2014-03-29 09:59:57.000000000 -0400
@@ -316,7 +316,7 @@
 		break;
 
 	case AF_INET6:
-		if (!IN6_IS_ADDR_UNSPECIFIED(&((struct sockaddr_in6 *) &bound)->sin6_addr))) {
+		if (!IN6_IS_ADDR_UNSPECIFIED(&((struct sockaddr_in6 *) &bound)->sin6_addr)) {
 			from = NULL;
 		}
 		break;
