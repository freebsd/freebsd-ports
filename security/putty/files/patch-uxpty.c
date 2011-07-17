--- ./uxpty.c.orig	2011-03-02 20:12:42.000000000 +0100
+++ ./uxpty.c	2011-07-17 14:55:44.000000000 +0200
@@ -13,7 +13,6 @@
 #include <fcntl.h>
 #include <termios.h>
 #include <grp.h>
-#include <utmp.h>
 #include <pwd.h>
 #include <time.h>
 #include <sys/types.h>
