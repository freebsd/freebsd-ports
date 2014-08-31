--- freebsd/freebsd/dahdi/bsd-compat.c.orig	2014-09-01 00:42:34.000000000 +0700
+++ freebsd/freebsd/dahdi/bsd-compat.c	2014-09-01 00:47:49.000000000 +0700
@@ -45,7 +45,7 @@
 
 #include <dahdi/compat/bsd.h>
 
-SYSCTL_NODE(, OID_AUTO, dahdi, CTLFLAG_RW, 0, "DAHDI");
+SYSCTL_ROOT_NODE(OID_AUTO, dahdi, CTLFLAG_RW, 0, "DAHDI");
 SYSCTL_NODE(_dahdi, OID_AUTO, echocan, CTLFLAG_RW, 0, "DAHDI Echo Cancelers");
 
 /*
