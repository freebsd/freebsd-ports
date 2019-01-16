--- src/ipopd/ipop3d.c.orig	2008-06-04 20:18:34.000000000 +0200
+++ src/ipopd/ipop3d.c	2009-01-16 10:19:50.000000000 +0100
@@ -113,7 +113,7 @@
     (((s = strrchr (argv[0],'/')) || (s = strrchr (argv[0],'\\'))) ?
      s+1 : argv[0]) : "ipop3d";
 				/* set service name before linkage */
-  mail_parameters (NIL,SET_SERVICENAME,(void *) "pop");
+  mail_parameters (NIL,SET_SERVICENAME,(void *) "pop3");
 #include "linkage.c"
 				/* initialize server */
   server_init (pgmname,"pop3","pop3s",clkint,kodint,hupint,trmint,NIL);
