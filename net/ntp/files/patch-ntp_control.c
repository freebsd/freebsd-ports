--- ntpd/ntp_control.c.orig	Sat Jul 15 23:46:05 2000
+++ ntpd/ntp_control.c	Fri Apr  6 01:05:57 2001
@@ -1821,9 +1821,19 @@
 					while (cp < reqend &&
 					    isspace((int)*cp))
 						cp++;
-					while (cp < reqend && *cp !=
-					    ',')
+					while (cp < reqend && *cp != ',') {
 						*tp++ = *cp++;
+						if (tp > buf + sizeof(buf)) {
+							msyslog(LOG_WARNING, "Attempted \"ntpdx\" exploit from IP %d.%d.%d.%d:%d (possibly spoofed)\n",
+	(ntohl(rmt_addr->sin_addr.s_addr) >> 24) & 0xff,
+	(ntohl(rmt_addr->sin_addr.s_addr) >> 16) & 0xff,
+	(ntohl(rmt_addr->sin_addr.s_addr) >> 8) & 0xff,
+	(ntohl(rmt_addr->sin_addr.s_addr) >> 0) & 0xff,
+	ntohs(rmt_addr->sin_port)
+);
+							return (0);
+						}
+					}
 					if (cp < reqend)
 						cp++;
 					*tp = '\0';
