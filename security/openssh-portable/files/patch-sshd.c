--- sshd.c.orig	2010-04-15 23:56:22.000000000 -0600
+++ sshd.c	2010-09-14 16:14:13.000000000 -0600
@@ -83,6 +83,13 @@
 #include <prot.h>
 #endif
 
+#ifdef __FreeBSD__
+#include <resolv.h>
+#ifdef GSSAPI
+#include "ssh-gss.h"
+#endif
+#endif
+
 #include "xmalloc.h"
 #include "ssh.h"
 #include "ssh1.h"
@@ -1864,6 +1871,29 @@
 	signal(SIGCHLD, SIG_DFL);
 	signal(SIGINT, SIG_DFL);
 
+#ifdef __FreeBSD__
+	/*
+	 * Initialize the resolver.  This may not happen automatically
+	 * before privsep chroot().                                   
+	 */
+	if ((_res.options & RES_INIT) == 0) {
+		debug("res_init()");         
+		res_init();         
+	}
+#ifdef GSSAPI
+	/*
+	 * Force GSS-API to parse its configuration and load any
+	 * mechanism plugins.
+	 */
+	{
+		gss_OID_set mechs;
+		OM_uint32 minor_status;
+		gss_indicate_mechs(&minor_status, &mechs);
+		gss_release_oid_set(&minor_status, &mechs);
+	}
+#endif
+#endif
+
 	/*
 	 * Register our connection.  This turns encryption off because we do
 	 * not have a key.
