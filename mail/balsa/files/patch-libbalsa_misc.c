--- libbalsa/misc.c.orig	Fri Feb 18 18:05:54 2005
+++ libbalsa/misc.c	Sat Mar 19 14:44:04 2005
@@ -23,7 +23,9 @@
 #include "config.h"
 
 #define _SVID_SOURCE           1
+#ifndef __FreeBSD__
 #define _XOPEN_SOURCE          500
+#endif
 #include <ctype.h>
 #include <dirent.h>
 #include <errno.h>
