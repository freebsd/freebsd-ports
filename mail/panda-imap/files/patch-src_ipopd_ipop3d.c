--- src/ipopd/ipop3d.c.orig	2022-04-17 00:12:02 UTC
+++ src/ipopd/ipop3d.c
@@ -113,7 +113,7 @@ int main (int argc,char *argv[])
     (((s = strrchr (argv[0],'/')) || (s = strrchr (argv[0],'\\'))) ?
      s+1 : argv[0]) : "ipop3d";
 				/* set service name before linkage */
-  mail_parameters (NIL,SET_SERVICENAME,(void *) "pop");
+  mail_parameters (NIL,SET_SERVICENAME,(void *) "pop3");
 #include "linkage.c"
 				/* initialize server */
   server_init (pgmname,"pop3","pop3s",clkint,kodint,hupint,trmint,NIL);
