--- bsd-kmod/dahdi/dahdi-bsd.c.orig	2014-09-01 01:18:32.000000000 +0700
+++ bsd-kmod/dahdi/dahdi-bsd.c	2014-09-01 01:18:41.000000000 +0700
@@ -38,7 +38,7 @@
 
 MALLOC_DEFINE(M_DAHDI, "dahdi", "DAHDI interface data structures");
 
-SYSCTL_NODE(, OID_AUTO, dahdi, CTLFLAG_RW, 0, "DAHDI");
+SYSCTL_ROOT_NODE(OID_AUTO, dahdi, CTLFLAG_RW, 0, "DAHDI");
 SYSCTL_NODE(_dahdi, OID_AUTO, echocan, CTLFLAG_RW, 0, "DAHDI Echo Cancelers");
 
 void
