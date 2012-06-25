--- ./src/main.h.orig	2012-06-24 16:20:15.000000000 +0200
+++ ./src/main.h	2012-06-25 19:43:27.000000000 +0200
@@ -98,6 +98,7 @@
 #endif // GUI_GTK
 
 #include <stdlib.h>
+#include <sys/stat.h>
 #include <stdio.h>
 #include <unistd.h>
 #include <string.h>
