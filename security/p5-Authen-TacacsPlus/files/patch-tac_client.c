--- tacpluslib/tac_client.c~	Mon May 10 20:01:48 1999
+++ tacpluslib/tac_client.c	Mon Mar 12 11:40:00 2001
@@ -1,14 +1,14 @@
 
 /* (C) 1997 Mike Shoyher msh@corbina.net, msh@apache.lexa.ru */
 
+#include <sys/types.h> 
+#include <sys/time.h>  
 #include<netdb.h>
 #include<stdio.h>
 #include<netinet/in.h>
 #include<sys/socket.h>
 #include<string.h>
 #include<stdlib.h>
-#include <sys/types.h> 
-#include <sys/time.h>  
 #include <unistd.h>    
 #include"tac_plus.h"
 #include "tacplus_client.h"
