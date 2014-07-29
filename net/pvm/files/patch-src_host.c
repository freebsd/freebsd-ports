--- src/host.c	Wed Sep 26 19:35:18 2001
+++ src/host.c	Thu Oct 31 13:57:18 2002
@@ -992,9 +992,7 @@
 			perror("ioctl");
 			goto bail;
 		}
-		/* On some FreeBSD systems: */
-		/* if (IFF_UP & req.ifr_flags) { */
-		if (IFF_UP & req.ifr_ifru.ifru_flags) {
+		if (IFF_UP & req.ifr_flags) {
 			if (nip > 0 && !(nip % 10))
 				iplist = TREALLOC(iplist, (nip + 10), struct in_addr);
 			iplist[nip++] =
