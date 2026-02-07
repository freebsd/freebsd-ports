--- checkfaillog.c.orig	2020-04-11 16:27:51 UTC
+++ checkfaillog.c
@@ -32,8 +32,9 @@
  */
 
 #include <stdio.h>
+#include <stdlib.h>
 #include <sys/types.h>
-#include <utmp.h>
+#include <utmpx.h>
 #include <pwd.h>
 
 #include "config.h"
