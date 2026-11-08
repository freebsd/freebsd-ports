--- lib/util/statvfs.c.orig	2026-10-23 22:29:46.143274800 +0700
+++ lib/util/statvfs.c	2026-10-26 11:35:01.300717000 +0700
@@ -25,6 +25,9 @@
 #include "statvfs.h"
 #include "lib/util/debug.h"
 
+#include <sys/param.h>
+#include <sys/mount.h>
+
 #if defined(DARWINOS)
 #include <sys/attr.h>
 
