--- src/pacman/conf.c.orig	2020-12-03 11:37:30 UTC
+++ src/pacman/conf.c
@@ -23,6 +23,7 @@
 #include <locale.h> /* setlocale */
 #include <fcntl.h> /* open */
 #include <glob.h>
+#include <signal.h>
 #include <stdlib.h>
 #include <stdio.h>
 #include <string.h> /* strdup */
