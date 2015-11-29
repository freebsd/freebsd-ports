--- dhcp6c.c.orig	2008-06-15 07:48:41 UTC
+++ dhcp6c.c
@@ -67,6 +67,7 @@
 #include <string.h>
 #include <err.h>
 #include <ifaddrs.h>
+#include <fcntl.h>
 
 #include <dhcp6.h>
 #include <config.h>
@@ -257,7 +258,7 @@ client6_init()
 {
 	struct addrinfo hints, *res;
 	static struct sockaddr_in6 sa6_allagent_storage;
-	int error, on = 1;
+	int error, on = 0;
 
 	/* get our DUID */
 	if (get_duid(DUID_FILE, &client_duid)) {
@@ -287,6 +288,20 @@ client6_init()
 		dprintf(LOG_ERR, FNAME, "socket");
 		exit(1);
 	}
+
+	if ((on = fcntl(sock, F_GETFL, 0)) == -1) {
+		dprintf(LOG_ERR, FNAME, "fctnl getflags");
+		exit(1);
+	}
+
+	on |= FD_CLOEXEC;
+
+	if ((on = fcntl(sock, F_SETFL, on)) == -1) {
+		dprintf(LOG_ERR, FNAME, "fctnl setflags");
+		exit(1);
+	}
+
+	on = 1;
 	if (setsockopt(sock, SOL_SOCKET, SO_REUSEPORT,
 		       &on, sizeof(on)) < 0) {
 		dprintf(LOG_ERR, FNAME,
@@ -1828,15 +1843,6 @@ client6_recvreply(ifp, dh6, len, optinfo
 	}
 
 	/*
-	 * Call the configuration script, if specified, to handle various
-	 * configuration parameters.
-	 */
-	if (ifp->scriptpath != NULL && strlen(ifp->scriptpath) != 0) {
-		dprintf(LOG_DEBUG, FNAME, "executes %s", ifp->scriptpath);
-		client6_script(ifp->scriptpath, state, optinfo);
-	}
-
-	/*
 	 * Set refresh timer for configuration information specified in
 	 * information-request.  If the timer value is specified by the server
 	 * in an information refresh time option, use it; use the protocol
@@ -1888,6 +1894,15 @@ client6_recvreply(ifp, dh6, len, optinfo
 		    &optinfo->serverID, ev->authparam);
 	}
 
+	/*
+	 * Call the configuration script, if specified, to handle various
+	 * configuration parameters.
+	 */
+	if (ifp->scriptpath != NULL && strlen(ifp->scriptpath) != 0) {
+		dprintf(LOG_DEBUG, FNAME, "executes %s", ifp->scriptpath);
+		client6_script(ifp->scriptpath, state, optinfo);
+	}
+
 	dhcp6_remove_event(ev);
 
 	if (state == DHCP6S_RELEASE) {
