--- sorcery.c.orig	Sun Nov 10 21:13:36 2002
+++ sorcery.c	Sun Nov 10 21:14:18 2002
@@ -152,7 +152,7 @@
  if(exi.READ_IT) {
  
   /* open second socket for snooping them packets */
-  if((snoop = socket(PF_PACKET, SOCK_PACKET, ETH_P_ALL)) == -1)
+  if((snoop = socket(PF_INET, SOCK_RAW, 0)) == -1)
   {
     perror("snoop socket");
     exit(snoop);
