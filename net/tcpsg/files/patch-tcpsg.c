--- ./tcpsg.c.orig	2002-10-25 00:00:42.000000000 +0200
+++ ./tcpsg.c	2014-02-24 16:25:44.577054255 +0100
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
+  i=read_config("/usr/local/etc/tcpsg.conf");
   if (i==0)
   {
     for (i=0;i<main_opt.num_servers;i++)
