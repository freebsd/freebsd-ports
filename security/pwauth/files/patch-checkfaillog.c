--- checkfaillog.c.orig	2012-02-11 13:22:09.000000000 +0200
+++ checkfaillog.c	2012-02-11 13:22:42.000000000 +0200
@@ -32,6 +32,7 @@
  */
 
 #include <stdio.h>
+#include <stdlib.h>
 #include <sys/types.h>
 #include <utmp.h>
 #include <pwd.h>
