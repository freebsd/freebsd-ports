--- utmp.c.orig	2024-03-26 16:41:57.000000000 -0700
+++ utmp.c	2024-04-03 11:21:49.696125000 -0700
@@ -30,6 +30,7 @@
 
 #include "utmp.h"
 
+#include <sys/param.h>
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>
@@ -64,9 +65,7 @@
 
 static int utmpok;
 static char UtmpName[] = UTMPXFILE;
-#ifndef UTMP_HELPER
 static int utmpfd = -1;
-#endif
 
 #undef  D_loginhost
 #define D_loginhost D_utmp_logintty.ut_host
