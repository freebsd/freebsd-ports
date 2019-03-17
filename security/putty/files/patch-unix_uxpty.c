--- unix/uxpty.c.orig	2019-03-16 12:26:38 UTC
+++ unix/uxpty.c
@@ -13,7 +13,6 @@
 #include <fcntl.h>
 #include <termios.h>
 #include <grp.h>
-#include <utmp.h>
 #include <pwd.h>
 #include <time.h>
 #include <sys/types.h>
