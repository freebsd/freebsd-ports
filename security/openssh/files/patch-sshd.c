--- sshd.c.orig	Mon Mar 24 05:01:09 2003
+++ sshd.c	Mon Mar 24 05:01:36 2003
@@ -49,6 +49,10 @@
 #include <openssl/md5.h>
 #include <openssl/rand.h>
 
+#ifdef __FreeBSD__
+#include <resolv.h>
+#endif
+
 #include "ssh.h"
 #include "ssh1.h"
 #include "ssh2.h"
@@ -88,6 +92,12 @@
 int deny_severity = LOG_WARNING;
 #endif /* LIBWRAP */
 
+#ifdef __FreeBSD__
+#include <libutil.h>
+#include <syslog.h>
+#include <time.h>
+#endif /* __FreeBSD__ */
+
 #ifndef O_NOCTTY
 #define O_NOCTTY	0
 #endif
@@ -1365,6 +1375,17 @@
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
