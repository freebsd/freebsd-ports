--- ./tacpluslib/tac_client.c.orig	2009-07-10 00:34:49.000000000 +0200
+++ ./tacpluslib/tac_client.c	2011-08-11 20:22:06.000000000 +0200
@@ -1,6 +1,8 @@
 
 /* (C) 1997 Mike Shoyher msh@corbina.net, msh@apache.lexa.ru */
 
+#include <sys/types.h> 
+#include <sys/time.h>  
 #include<netdb.h>
 #include<stdio.h>
 #include<netinet/in.h>
@@ -8,8 +10,6 @@
 #include<arpa/inet.h>
 #include<string.h>
 #include<stdlib.h>
-#include <sys/types.h> 
-#include <sys/time.h>  
 #include <unistd.h>  
 #include <time.h>  
 #include"tac_plus.h"
