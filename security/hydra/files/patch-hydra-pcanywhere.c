--- hydra-pcanywhere.c.orig	Wed Sep  7 21:59:26 2005
+++ hydra-pcanywhere.c	Mon Oct 10 20:22:28 2005
@@ -111,8 +111,9 @@
   char clogin[128]="";
   char cpass[128]="";
   int ret,i;
-
+  char *server[5];
   char *client[4];
+
   int clientsize[4];
   client[0]="\x00\x00\x00\x00";
   clientsize[0]=4;
@@ -123,7 +124,6 @@
   client[3]="\x6f\x62\x01\x02\x00\x00\x00";
   clientsize[3]=7;
 
-  char *server[5];
   server[0]= "nter";
   server[1]="\x1B\x61"; 
   server[2]="\0x1B\0x62";
