--- bsd-kmod/dahdi/dahdi-bsd.c.orig	2012-09-28 02:45:50.000000000 +0700
+++ bsd-kmod/dahdi/dahdi-bsd.c	2014-09-13 19:23:54.000000000 +0700
@@ -38,7 +38,11 @@
 
 MALLOC_DEFINE(M_DAHDI, "dahdi", "DAHDI interface data structures");
 
+#if __FreeBSD_version >= 1100024
+SYSCTL_ROOT_NODE(OID_AUTO, dahdi, CTLFLAG_RW, 0, "DAHDI");
+#else
 SYSCTL_NODE(, OID_AUTO, dahdi, CTLFLAG_RW, 0, "DAHDI");
+#endif
 SYSCTL_NODE(_dahdi, OID_AUTO, echocan, CTLFLAG_RW, 0, "DAHDI Echo Cancelers");
 
 void
