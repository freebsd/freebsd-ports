--- tty.c	Sun Mar 30 22:57:59 2003
+++ tty.c	Thu Mar 15 22:48:59 2007
@@ -86,11 +86,11 @@
 #include <sgtty.h>
 struct sgttyb oldsb, newsb;
 #else
-#ifndef POSIX
-#include <termio.h>
 #ifndef NCC
 #define NCC NCCS
 #endif
+#ifndef POSIX
+#include <termio.h>
 struct termio oldsb, newsb;
 #else
 #include <termios.h>
--- tty_aux.c	Sun Mar 30 22:57:59 2003
+++ tty_aux.c	Thu Mar 15 22:48:59 2007
@@ -86,11 +86,11 @@
 #include <sgtty.h>
 struct sgttyb oldsb, newsb;
 #else
-#ifndef POSIX
-#include <termio.h>
 #ifndef NCC
 #define NCC NCCS
 #endif
+#ifndef POSIX
+#include <termio.h>
 struct termio oldsb, newsb;
 #else
 #include <termios.h>
