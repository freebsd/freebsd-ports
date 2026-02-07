--- tacpluslib/tac_client.c.orig	2012-08-23 07:25:52 UTC
+++ tacpluslib/tac_client.c
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
