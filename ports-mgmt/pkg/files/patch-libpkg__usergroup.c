--- ./libpkg/usergroup.c.orig	2012-06-25 14:58:21.000000000 +0200
+++ ./libpkg/usergroup.c	2012-06-27 08:23:34.206379508 +0200
@@ -32,7 +32,7 @@
 #include <libutil.h>
 #include <string.h>
 
-#if __FreeBSD_version < 1000003
+#ifndef HAVE_GRUTILS
 #include "private/gr_util.h"
 #endif
 #include "pkg.h"
