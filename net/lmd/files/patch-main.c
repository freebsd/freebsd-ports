--- main.c.orig	Mon Nov 26 06:45:34 2001
+++ main.c	Tue May 14 14:09:46 2002
@@ -1,7 +1,7 @@
 #include "main.h"
 #include <math.h>
 #define TIMETOSLEEP 60
-#define CONFIGFILE "/usr/local/etc/lmd.conf"
+#define CONFIGFILE PREFIX "/etc/lmd.conf"
 
 char bufferout[2][1024];
 char **loaddservers;
