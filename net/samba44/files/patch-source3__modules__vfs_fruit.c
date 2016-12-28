--- source3/modules/vfs_fruit.c.orig	2016-12-28 02:48:27.478460000 +0000
+++ source3/modules/vfs_fruit.c	2016-12-28 02:48:58.141967000 +0000
@@ -105,7 +105,7 @@
  * This is hokey, but what else can we do?
  */
 #define NETATALK_META_XATTR "org.netatalk.Metadata"
-#if defined(HAVE_ATTROPEN) || defined(FREEBSD)
+#if defined(HAVE_ATTROPEN)
 #define AFPINFO_EA_NETATALK NETATALK_META_XATTR
 #define AFPRESOURCE_EA_NETATALK "org.netatalk.ResourceFork"
 #else
