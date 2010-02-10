--- uxpty.c.orig	2010-02-10 20:05:47.000000000 +0000
+++ uxpty.c	2010-02-10 20:06:06.000000000 +0000
@@ -13,7 +13,6 @@
 #include <fcntl.h>
 #include <termios.h>
 #include <grp.h>
-#include <utmp.h>
 #include <pwd.h>
 #include <time.h>
 #include <sys/types.h>
