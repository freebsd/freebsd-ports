--- sshd.c.orig	Wed Jun 26 01:24:19 2002
+++ sshd.c	Thu Jul 25 06:32:37 2002
@@ -53,6 +53,10 @@
 #include <prot.h>
 #endif
 
+#ifdef __FreeBSD__
+#include <resolv.h>
+#endif
+
 #include "ssh.h"
 #include "ssh1.h"
 #include "ssh2.h"
@@ -1409,6 +1413,17 @@
 	    setsockopt(sock_in, SOL_SOCKET, SO_KEEPALIVE, &on,
 	    sizeof(on)) < 0)
 		error("setsockopt SO_KEEPALIVE: %.100s", strerror(errno));
+
+#ifdef __FreeBSD__
+	/*
+	 * Initialize the resolver.  This may not happen automatically
+	 * before privsep chroot().                                   
+	 */
+	if ((_res.options & RES_INIT) == 0) {
+		debug("res_init()");         
+		res_init();         
+	}
+#endif
 
 	/*
 	 * Register our connection.  This turns encryption off because we do
