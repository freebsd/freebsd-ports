--- common/discover.c.orig	Fri Jul 25 21:44:15 2003
+++ common/discover.c	Fri Mar  5 23:33:04 2004
@@ -47,6 +47,7 @@
 #endif /* not lint */
 
 #include "dhcpd.h"
+#include <ifaddrs.h>
 #include <sys/ioctl.h>
 
 struct interface_info *interfaces, *dummy_interfaces, *fallback_interface;
@@ -135,10 +136,7 @@
 {
 	struct interface_info *tmp, *ip;
 	struct interface_info *last, *next;
-	char buf [2048];
-	struct ifconf ic;
-	struct ifreq ifr;
-	int i;
+	struct ifaddrs *ifap, *ifa;
 	int sock;
 	int address_count = 0;
 	struct subnet *subnet;
@@ -157,61 +155,6 @@
 	if ((sock = socket (AF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0)
 		log_fatal ("Can't create addrlist socket");
 
-	/* Get the interface configuration information... */
-
-#ifdef SIOCGIFCONF_ZERO_PROBE
-	/* linux will only tell us how long a buffer it wants if we give it
-	 * a null buffer first. So, do a dry run to figure out the length.
-	 * 
-	 * XXX this code is duplicated from below because trying to fold
-	 * the logic into the if statement and goto resulted in excesssive
-	 * obfuscation. The intent is that unless you run Linux you shouldn't
-	 * have to deal with this. */
-
-	ic.ifc_len = 0;
-	ic.ifc_ifcu.ifcu_buf = (caddr_t)NULL;
-#else
-	/* otherwise, we just feed it a starting size, and it'll tell us if
-	 * it needs more */
-
-	ic.ifc_len = sizeof buf;
-	ic.ifc_ifcu.ifcu_buf = (caddr_t)buf;
-#endif
-
-      gifconf_again:
-	i = ioctl(sock, SIOCGIFCONF, &ic);
-
-	if (i < 0)
-		log_fatal ("ioctl: SIOCGIFCONF: %m");
-
-#ifdef SIOCGIFCONF_ZERO_PROBE
-	/* Workaround for SIOCGIFCONF bug on some Linux versions. */
-	if (ic.ifc_ifcu.ifcu_buf == 0 && ic.ifc_len == 0) {
-		ic.ifc_len = sizeof buf;
-		ic.ifc_ifcu.ifcu_buf = (caddr_t)buf;
-		goto gifconf_again;
-	}
-#endif
-
-	/* If the SIOCGIFCONF resulted in more data than would fit in
-	   a buffer, allocate a bigger buffer. */
-	if ((ic.ifc_ifcu.ifcu_buf == buf 
-#ifdef SIOCGIFCONF_ZERO_PROBE
-	     || ic.ifc_ifcu.ifcu_buf == 0
-#endif
-		) && ic.ifc_len > sizeof buf) {
-		ic.ifc_ifcu.ifcu_buf = dmalloc ((size_t)ic.ifc_len, MDL);
-		if (!ic.ifc_ifcu.ifcu_buf)
-			log_fatal ("Can't allocate SIOCGIFCONF buffer.");
-		goto gifconf_again;
-#ifdef SIOCGIFCONF_ZERO_PROBE
-	} else if (ic.ifc_ifcu.ifcu_buf == 0) {
-		ic.ifc_ifcu.ifcu_buf = (caddr_t)buf;
-		ic.ifc_len = sizeof buf;
-		goto gifconf_again;
-#endif
-	}
-
 		
 	/* If we already have a list of interfaces, and we're running as
 	   a DHCP server, the interfaces were requested. */
@@ -224,51 +167,38 @@
 	else
 		ir = INTERFACE_REQUESTED;
 
+	if (getifaddrs(&ifap) != 0)
+		log_fatal ("getifaddrs failed");
+
 	/* Cycle through the list of interfaces looking for IP addresses. */
-	for (i = 0; i < ic.ifc_len;) {
-		struct ifreq *ifp = (struct ifreq *)((caddr_t)ic.ifc_req + i);
-#ifdef HAVE_SA_LEN
-		if (ifp -> ifr_addr.sa_len > sizeof (struct sockaddr))
-			i += (sizeof ifp -> ifr_name) + ifp -> ifr_addr.sa_len;
-		else
-#endif
-			i += sizeof *ifp;
+	for (ifa = ifap; ifa != NULL; ifa = ifa->ifa_next) {
 
 #ifdef ALIAS_NAMES_PERMUTED
-		if ((s = strrchr (ifp -> ifr_name, ':'))) {
+		if ((s = strrchr (ifa -> ifa_name, ':'))) {
 			*s = 0;
 		}
 #endif
 
 #ifdef SKIP_DUMMY_INTERFACES
-		if (!strncmp (ifp -> ifr_name, "dummy", 5))
+		if (!strncmp (ifa -> ifa_name, "dummy", 5))
 			continue;
 #endif
 
-
-		/* See if this is the sort of interface we want to
-		   deal with. */
-		strcpy (ifr.ifr_name, ifp -> ifr_name);
-		if (ioctl (sock, SIOCGIFFLAGS, &ifr) < 0)
-			log_fatal ("Can't get interface flags for %s: %m",
-			       ifr.ifr_name);
-
 		/* See if we've seen an interface that matches this one. */
 		for (tmp = interfaces; tmp; tmp = tmp -> next)
-			if (!strcmp (tmp -> name, ifp -> ifr_name))
+			if (!strcmp (tmp -> name, ifa -> ifa_name))
 				break;
 
-		/* Skip non broadcast interfaces (plus loopback and
-		   point-to-point in case an OS incorrectly marks them
-		   as broadcast). Also skip down interfaces unless we're
+		/* See if this is the sort of interface we want to
+		   deal with.  Skip loopback, point-to-point and down
+		   interfaces, except don't skip down interfaces if we're
 		   trying to get a list of configurable interfaces. */
-		if (((!(ifr.ifr_flags & IFF_BROADCAST) ||
-		      ifr.ifr_flags & IFF_LOOPBACK ||
-		      ifr.ifr_flags & IFF_POINTOPOINT) && !tmp) ||
-		    (!(ifr.ifr_flags & IFF_UP) &&
+		if ((ifa->ifa_flags & IFF_LOOPBACK) ||
+		     (ifa->ifa_flags & IFF_POINTOPOINT) ||
+		     (!(ifa->ifa_flags & IFF_UP) &&
 		     state != DISCOVER_UNCONFIGURED))
 			continue;
-		
+
 		/* If there isn't already an interface by this name,
 		   allocate one. */
 		if (!tmp) {
@@ -276,9 +206,9 @@
 			status = interface_allocate (&tmp, MDL);
 			if (status != ISC_R_SUCCESS)
 				log_fatal ("Error allocating interface %s: %s",
-					   ifp -> ifr_name,
+					   ifa -> ifa_name,
 					   isc_result_totext (status));
-			strcpy (tmp -> name, ifp -> ifr_name);
+			strcpy (tmp -> name, ifa -> ifa_name);
 			interface_snorf (tmp, ir);
 			interface_dereference (&tmp, MDL);
 			tmp = interfaces; /* XXX */
@@ -290,9 +220,9 @@
 		/* If we have the capability, extract link information
 		   and record it in a linked list. */
 #ifdef HAVE_AF_LINK
-		if (ifp -> ifr_addr.sa_family == AF_LINK) {
+		if (ifa -> ifa_addr->sa_family == AF_LINK) {
 			struct sockaddr_dl *foo = ((struct sockaddr_dl *)
-						   (&ifp -> ifr_addr));
+						   (ifa -> ifa_addr));
 #if defined (HAVE_SIN_LEN)
 			tmp -> hw_address.hlen = foo -> sdl_alen;
 #else
@@ -305,12 +235,11 @@
 		} else
 #endif /* AF_LINK */
 
-		if (ifp -> ifr_addr.sa_family == AF_INET) {
+		if (ifa -> ifa_addr->sa_family == AF_INET) {
 			struct iaddr addr;
 
 			/* Get a pointer to the address... */
-			memcpy (&foo, &ifp -> ifr_addr,
-				sizeof ifp -> ifr_addr);
+			bcopy(ifa->ifa_addr, &foo, sizeof(foo));
 
 			/* We don't want the loopback interface. */
 			if (foo.sin_addr.s_addr == htonl (INADDR_LOOPBACK) &&
@@ -323,16 +252,15 @@
 			   found, keep a pointer to ifreq structure in
 			   which we found it. */
 			if (!tmp -> ifp) {
-#ifdef HAVE_SA_LEN
-				unsigned len = ((sizeof ifp -> ifr_name) +
-						ifp -> ifr_addr.sa_len);
-#else
-				unsigned len = sizeof *ifp;
-#endif
+
+				int len = (IFNAMSIZ +
+					ifa -> ifa_addr->sa_len);
 				tif = (struct ifreq *)dmalloc (len, MDL);
 				if (!tif)
 					log_fatal ("no space for ifp.");
-				memcpy (tif, ifp, len);
+				strlcpy(tif->ifr_name, ifa->ifa_name, IFNAMSIZ);
+				memcpy(&tif->ifr_addr, ifa->ifa_addr,
+					ifa->ifa_addr->sa_len);
 				tmp -> ifp = tif;
 				tmp -> primary_address = foo.sin_addr;
 			}
@@ -346,9 +274,6 @@
 		}
 	}
 
-	/* If we allocated a buffer, free it. */
-	if (ic.ifc_ifcu.ifcu_buf != buf)
-		dfree (ic.ifc_ifcu.ifcu_buf, MDL);
 
 #if defined (LINUX_SLASHPROC_DISCOVERY)
 	/* On Linux, interfaces that don't have IP addresses don't
@@ -529,6 +454,7 @@
 	   be able to configure, we can quit now. */
 	if (state == DISCOVER_UNCONFIGURED) {
 		close (sock);
+		freeifaddrs(ifap);
 		return;
 	}
 
@@ -674,6 +600,7 @@
 	}
 
 	close (sock);
+	freeifaddrs(ifap);
 
 	if (state == DISCOVER_SERVER && wifcount == 0) {
 		log_info ("%s", "");
