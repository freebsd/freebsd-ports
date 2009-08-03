$FreeBSD$
--- ntpd.h.orig	2009-01-16 15:03:38.000000000 +0100
+++ ntpd.h	2009-08-01 22:31:40.000000000 +0200
@@ -29,10 +29,11 @@
 #include <pwd.h>
 #include <stdarg.h>
 
+#include "compat.h"
 #include "ntp.h"
 
 #define	NTPD_USER	"_ntp"
-#define	CONFFILE	"/etc/ntpd.conf"
+#define	CONFFILE	"%%PREFIX%%/etc/ntpd.conf"
 #define DRIFTFILE	"/var/db/ntpd.drift"
 
 #define	READ_BUF_SIZE		8192
