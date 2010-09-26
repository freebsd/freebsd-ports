--- inet.c.orig	2010-03-11 20:56:54.000000000 -0500
+++ inet.c	2010-09-26 10:06:27.397182116 -0400
@@ -431,26 +431,36 @@
 	strlcpy(ifrdesc.ifr_name, name, sizeof ifrdesc.ifr_name);
 	s = socket(AF_INET, SOCK_DGRAM, 0);
 	if (s >= 0) {
+#ifdef __FreeBSD__
+		/*
+		 * On FreeBSD, if the buffer isn't big enough for the
+		 * description, the ioctl succeeds, but the description
+		 * isn't copied, ifr_buffer.length is set to the description
+		 * length, and ifr_buffer.buffer is set to NULL.
+		 */
 		for (;;) {
 			free(description);
 			if ((description = malloc(descrlen)) != NULL) {
-#ifdef __FreeBSD__
 				ifrdesc.ifr_buffer.buffer = description;
 				ifrdesc.ifr_buffer.length = descrlen;
-#else /* __FreeBSD__ */
-				ifrdesc.ifr_data = (caddr_t)description;
-#endif /* __FreeBSD__ */
-				if (ioctl(s, SIOCGIFDESCR, &ifrdesc) == 0)
-					break;
-#ifdef __FreeBSD__
-				else if (errno == ENAMETOOLONG)
-					descrlen = ifrdesc.ifr_buffer.length;
-#endif /* __FreeBSD__ */
-				else
+				if (ioctl(s, SIOCGIFDESCR, &ifrdesc) == 0) {
+					if (ifrdesc.ifr_buffer.buffer ==
+					    description)
+						break;
+					else
+						descrlen = ifrdesc.ifr_buffer.length;
+				} else {
+					/*
+					 * Failed to get interface description.
+					 */
+					free(description);
+					description = NULL;
 					break;
+				}
 			} else
 				break;
 		}
+#endif /* __FreeBSD__ */
 		close(s);
 		if (description != NULL && strlen(description) == 0) {
 			free(description);
