--- ./inet.c.orig	2008-08-31 22:44:54.000000000 -0400
+++ ./inet.c	2010-03-01 13:59:26.873317983 -0500
@@ -401,10 +401,15 @@
 	pcap_if_t *curdev;
 	char *description = NULL;
 	pcap_addr_t *curaddr, *prevaddr, *nextaddr;
+	int s;
 #ifdef SIOCGIFDESCR
 	struct ifreq ifrdesc;
+#ifndef IFDESCRSIZE
+#define _IFDESCRSIZE 64
+	char ifdescr[_IFDESCRSIZE];
+#else
 	char ifdescr[IFDESCRSIZE];
-	int s;
+#endif
 #endif
 
 #ifdef SIOCGIFDESCR
@@ -413,12 +418,17 @@
 	 */
 	memset(&ifrdesc, 0, sizeof ifrdesc);
 	strlcpy(ifrdesc.ifr_name, name, sizeof ifrdesc.ifr_name);
+#ifdef __FreeBSD__
+	ifrdesc.ifr_buffer.buffer = ifdescr;
+	ifrdesc.ifr_buffer.length = sizeof(ifdescr);
+#else
 	ifrdesc.ifr_data = (caddr_t)&ifdescr;
+#endif
 	s = socket(AF_INET, SOCK_DGRAM, 0);
 	if (s >= 0) {
 		if (ioctl(s, SIOCGIFDESCR, &ifrdesc) == 0 &&
-		    strlen(ifrdesc.ifr_data) != 0)
-			description = ifrdesc.ifr_data;
+		    strlen(ifdescr) != 0)
+			description = ifdescr;
 		close(s);
 	}
 #endif
