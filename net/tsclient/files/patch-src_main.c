--- src/main.c.orig	2007-04-12 03:21:51.000000000 +0900
+++ src/main.c	2022-09-08 13:45:37.689308000 +0900
@@ -17,6 +17,7 @@
 #include "support.h"
 #include "connect.h"
 
+extern GtkWidget *gConnect;
 
 static void tsc_print_help ();
 static void tsc_print_version ();
