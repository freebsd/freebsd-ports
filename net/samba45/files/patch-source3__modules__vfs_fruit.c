--- source3/modules/vfs_fruit.c.orig	2016-06-06 07:40:23 UTC
+++ source3/modules/vfs_fruit.c
@@ -105,7 +105,7 @@ static int vfs_fruit_debug_level = DBGC_
  * This is hokey, but what else can we do?
  */
 #define NETATALK_META_XATTR "org.netatalk.Metadata"
-#if defined(HAVE_ATTROPEN) || defined(FREEBSD)
+#if defined(HAVE_ATTROPEN)
 #define AFPINFO_EA_NETATALK NETATALK_META_XATTR
 #define AFPRESOURCE_EA_NETATALK "org.netatalk.ResourceFork"
 #else
