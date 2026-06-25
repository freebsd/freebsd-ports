diff --git a/bacula/src/console/conio.c b/bacula/src/console/conio.c
index 2bea887e7406433f57bee865b18f4bee3b11add0..7ac61d642fc92f4a2094d133be75bd03d5a9e1c2 100755
--- src/console/conio.c
+++ src/console/conio.c
@@ -56,6 +56,7 @@
 
 #include <curses.h>
 #include <term.h>
+#include <termios.h>
 
 #ifdef HAVE_SUN_OS
 #ifndef _TERM_H
