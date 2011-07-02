--- src/commands.c.orig	2011-06-19 22:52:25.000000000 +0900
+++ src/commands.c	2011-06-26 15:19:03.000000000 +0900
@@ -27,6 +27,8 @@
 #include <stdlib.h> /*  system() */
 #include <string.h> /* strncmp() */
 #include <time.h>
+#include <sys/types.h>
+#include <sys/wait.h>
 
 #include "background.h"
 #include "bookmarks.h"
