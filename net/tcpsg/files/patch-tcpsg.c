--- tcpsg.c.orig	Wed Oct 30 13:14:39 2002
+++ tcpsg.c	Wed Oct 30 13:41:13 2002
@@ -39,8 +39,8 @@
 
 /* Network Headers */
 #include <sys/socket.h>
-#include <arpa/inet.h>
 #include <netinet/in.h>
+#include <arpa/inet.h>
 #include <netdb.h>
 
 /* 
@@ -229,7 +229,7 @@
 int set_config()
 {
   int i,j;
-  i=read_config("/etc/tcpsg.conf");
+  i=read_config("%%PREFIX%%/etc/tcpsg.conf");
   if (i==0)
   {
     for (i=0;i<main_opt.num_servers;i++)
