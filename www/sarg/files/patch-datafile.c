--- datafile.c.orig	Wed Nov 30 13:58:14 2005
+++ datafile.c	Wed Nov 30 13:58:23 2005
@@ -25,7 +25,7 @@
 
 #include "include/conf.h"
 
-void saverecs(char *dirname, char *user, long long int nacc, char *url, long long int nbytes, char *ip, char *hora, char *dia, long long int nelap, long long int incache, long long int oucache);
+void saverecs2(char *dirname, char *user, long long int nacc, char *url, long long int nbytes, char *ip, char *hora, char *dia, long long int nelap, long long int incache, long long int oucache);
 void grava_SmartFilter(char *dirname, char *user, char *ip, char *data, char *hora, char *url, char *smart);
 
 void data_file(char *tmp)
