$FreeBSD$

--- 2.4.5/dgd/sys/driver.c.orig	2010-03-21 10:39:41.000000000 -0700
+++ 2.4.5/dgd/sys/driver.c	2010-03-23 21:53:25.000000000 -0700
@@ -3,6 +3,10 @@
 # include <status.h>
 # include "/dgd/lib/privilege.h"
 
+#ifdef __NETWORK_EXTENSIONS__
+#define	TELNET_PORT	2000
+#endif
+
 object *usr;		/* user array just before a swapout */
 
 /*
@@ -50,6 +54,9 @@
 	}
     }
     send_message("Setting up ipc.\n");
+#ifdef __NETWORK_EXTENSIONS__
+    open_port("telnet", TELNET_PORT);
+#endif
 }
 
 /*
@@ -249,6 +256,16 @@
     return user;
 }
 
+#ifdef __NETWORK_EXTENSIONS__
+/*
+ * NAME:	connection()
+ * DESCRIPTION:	return a user object.
+ */
+object connection(string ipnumber, int port) {
+    return telnet_connect(port);
+}
+#endif
+
 /*
  * NAME:	runtime_error()
  * DESCRIPTION:	log a runtime error
