--- libbalsa/misc.c.orig	Mon Jul 26 02:12:16 2004
+++ libbalsa/misc.c	Mon Jul 26 02:17:06 2004
@@ -23,7 +23,10 @@
 #include "config.h"
 
 #define _SVID_SOURCE           1
+#ifndef __FreeBSD__
 #define _XOPEN_SOURCE          500
+#endif
+#include <sys/types.h>
 #include <stdio.h>
 #include <sys/utsname.h>
 #include <ctype.h>
@@ -31,6 +34,7 @@
 #include <errno.h>
 #include <dirent.h>
 #include <sys/file.h>
+#include <sys/stat.h>
 
 #include <libgnomevfs/gnome-vfs-file-info.h>
 #include <libgnomevfs/gnome-vfs-ops.h>
