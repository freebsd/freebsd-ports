--- xorriso/xorriso.c.orig	2008-10-12 08:44:35.000000000 -0400
+++ xorriso/xorriso.c	2008-11-13 18:24:49.000000000 -0500
@@ -89,6 +89,8 @@
 #include <utime.h>
 #include <pwd.h>
 #include <grp.h>
+#include <sys/types.h>
+#include <signal.h>
 
 /* eventually, this is done in xorriso_private.h : #include <regex.h> */
 
