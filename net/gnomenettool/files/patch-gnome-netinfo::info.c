--- gnome-netinfo/info.c.orig	Mon Nov 24 18:29:43 2003
+++ gnome-netinfo/info.c	Wed Dec 17 22:27:46 2003
@@ -27,6 +27,7 @@
 #endif
 
 
+#include <netinet/in.h>
 #include <sys/socket.h>	/* basic socket definitions */
 #include <arpa/inet.h>	/* inet(3) functions */
 #include <sys/un.h>	/* for Unix domain sockets */
@@ -173,7 +174,7 @@
 	for (ptr = buf; ptr < buf + ifc.ifc_len;) {
 		ifr = (struct ifreq *) ptr;
 		len = sizeof (struct sockaddr);
-#ifdef	HAVE_SOCKADDR_SA_LEN
+#if	defined(HAVE_SOCKADDR_SA_LEN) || defined(__FreeBSD__)
 		if (ifr->ifr_addr.sa_len > len)
 			len = ifr->ifr_addr.sa_len;	/* length > 16 */
 #endif
@@ -182,8 +183,12 @@
 		if (strcmp (ifr->ifr_name, nic) != 0) {
 			continue;
 		}
+
+		memset (&data, 0, sizeof(data));
 		
+#ifdef __linux__
 		data = mii_get_basic (nic);
+#endif
 		
 		switch (ifr->ifr_addr.sa_family) {
 		case AF_INET:
@@ -306,7 +311,6 @@
 			break;
 		}
 	}
-	g_free (ifr);
 }
 
 static GList *
@@ -321,6 +325,8 @@
 
 	sockfd = socket (AF_INET, SOCK_DGRAM, 0);
 
+	memset (&ifc, 0, sizeof (struct ifconf));
+	memset (&buf, 0, sizeof (buf));
 	ifc.ifc_len = sizeof (buf);
 	ifc.ifc_req = (struct ifreq *) buf;
 
@@ -331,9 +337,11 @@
 		len = sizeof (struct sockaddr);
 
 		iface = g_strdup (ifr->ifr_name);
-		items = g_list_append (items, iface);
+		if (g_list_find_custom (items, iface, (GCompareFunc) g_ascii_strcasecmp) == NULL) {
+			items = g_list_append (items, iface);
+		}
 
-#ifdef	HAVE_SOCKADDR_SA_LEN
+#if defined(HAVE_SOCKADDR_SA_LEN) || defined(__FreeBSD__)
 		if (ifr->ifr_addr.sa_len > len)
 			len = ifr->ifr_addr.sa_len;	/* length > 16 */
 #endif
