--- reslimits.c.orig	Wed Jan 23 22:39:27 2002
+++ reslimits.c	Wed Jan 23 22:41:29 2002
@@ -9,8 +9,9 @@
 #ifndef NORLIMIT
 
 #include <stdio.h>
-#include <sys/resource.h>
+#include <sys/types.h>
 #include <sys/time.h>
+#include <sys/resource.h>
 
 reslimits( type, value )
 char *type;
