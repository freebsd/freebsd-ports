--- flowd.h.orig	2007-10-24 01:04:10 UTC
+++ flowd.h
@@ -35,7 +35,7 @@
 
 #define DEFAULT_CONFIG			SYSCONFDIR "/flowd.conf"
 #define DEFAULT_PIDFILE			PIDFILEDIR "/flowd.pid"
-#define PRIVSEP_USER			"_flowd"
+#define PRIVSEP_USER			"%%FLOWD_USER%%"
 
 /* Initial stateholding limits */
 /* XXX these are not actually tunable yet */
