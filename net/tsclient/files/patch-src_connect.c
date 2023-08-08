--- src/connect.c.orig	2007-04-12 03:15:35.000000000 +0900
+++ src/connect.c	2022-09-08 13:45:16.005967000 +0900
@@ -27,6 +27,7 @@
 #include "connect.h"
 #include "mrulist.h"
 
+GtkWidget *gConnect;
 
 /***************************************
 *                                      *
