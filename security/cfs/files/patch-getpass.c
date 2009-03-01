--- getpass.c
+++ getpass.c
@@ -35,7 +35,7 @@

 #include <stdio.h>
 #include <signal.h>
-#ifndef linux
+#if !defined(linux) && !defined(__FreeBSD__)
 #include <sgtty.h>
 #endif
 #include <sys/types.h>
@@ -45,7 +45,7 @@
 #include "cfs.h"
 #include "shs.h"

-#if defined(irix) || defined(linux)
+#if defined(irix) || defined(linux) || defined(__FreeBSD__)
 /* hacks to use POSIX style termios instead of old BSD style sgttyb */
 #include <termios.h>
 #define sgttyb termios
