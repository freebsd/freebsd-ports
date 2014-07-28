--- src/main.c.orig	Sat Apr 15 19:50:38 2000
+++ src/main.c	Sat Apr 15 19:50:52 2000
@@ -10,10 +10,13 @@
 #include "app.h"
 #include <gtk/gtk.h>
 #include <stdio.h>
+#include <ieeefp.h>
 
 int
 main(int argc, char *argv[])
 {
+  fpsetmask(0);
+
   parse_command_line(argc, argv);
   parse_rcfile();
 
