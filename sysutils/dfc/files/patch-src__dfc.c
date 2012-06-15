--- ./src/dfc.c.orig	2012-05-31 00:25:46.000000000 +0200
+++ ./src/dfc.c	2012-06-15 23:39:58.405538089 +0200
@@ -853,7 +853,7 @@
 #if defined(__FreeBSD__) || defined(__APPLE__)
 	{ MNT_MULTILABEL,         "multilabel"         },
 #endif
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) && __FreeBSD__version > 800000
 	{ MNT_NFS4ACLS,           "nfs4acls"           },
 #endif
 #if defined(__DragonFly__) || defined(__FreeBSD__) || defined(__NetBSD__) \
