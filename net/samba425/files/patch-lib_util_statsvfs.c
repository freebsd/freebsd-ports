--- lib/util/statvfs.c.orig	2026-08-11 02:16:53.026630200 +0700
+++ lib/util/statvfs.c	2026-10-07 15:44:13.317734000 +0700
@@ -24,6 +24,9 @@
 #include "libcli/smb/smb_constants.h"
 #include "statvfs.h"
 
+#include <sys/param.h>
+#include <sys/mount.h>
+
 #if defined(DARWINOS)
 #include <sys/attr.h>
 
@@ -79,7 +82,7 @@
 
 #if defined(BSD_STYLE_STATVFS)
 
-static void bsd_init_statvfs(const struct statvfs *src,
+static void bsd_init_statvfs(const struct statfs *src,
 			     struct vfs_statvfs_struct *dst)
 {
 	dst->OptimalTransferSize = src->f_iosize;
