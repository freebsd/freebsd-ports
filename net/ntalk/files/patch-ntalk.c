--- ntalk.c.orig	Sun Aug 26 08:02:08 2001
+++ ntalk.c	Sun Aug 26 08:02:22 2001
@@ -16,7 +16,7 @@
 #include <netinet/in.h>
 #include <arpa/inet.h>
 #include <unistd.h>
-#include <ncurses/ncurses.h>
+#include <curses.h>
 
 #define MESSAGE 	0   
 #define NICK      	1
