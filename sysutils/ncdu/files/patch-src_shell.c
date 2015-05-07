--- src/shell.c.orig	2015-05-07 14:48:25 UTC
+++ src/shell.c
@@ -29,6 +29,7 @@
 #include "dirlist.h"
 #include "util.h"
 
+#include <sys/wait.h>
 #include <ncurses.h>
 #include <stdlib.h>
 #include <unistd.h>
