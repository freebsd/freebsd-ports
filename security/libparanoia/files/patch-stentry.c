--- stentry.c.orig	Tue Nov  4 01:27:18 2003
+++ stentry.c	Tue Nov  4 01:27:23 2003
@@ -2,7 +2,6 @@
 #include <signal.h>
 #include <stdio.h>
 #include <syslog.h>
-#include <varargs.h>
 #include <string.h>
 
 static unsigned long save[10];
