--- freebsd/freebsd/dahdi/bsd-compat.c.orig	2014-09-13 19:10:00.000000000 +0700
+++ freebsd/freebsd/dahdi/bsd-compat.c	2014-09-13 19:10:59.000000000 +0700
@@ -45,7 +45,11 @@
 
 #include <dahdi/compat/bsd.h>
 
+#if __FreeBSD_version >= 1100024
+SYSCTL_ROOT_NODE(OID_AUTO, dahdi, CTLFLAG_RW, 0, "DAHDI");
+#else
 SYSCTL_NODE(, OID_AUTO, dahdi, CTLFLAG_RW, 0, "DAHDI");
+#endif
 SYSCTL_NODE(_dahdi, OID_AUTO, echocan, CTLFLAG_RW, 0, "DAHDI Echo Cancelers");
 
 /*
