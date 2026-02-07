--- tcpview.h.orig	1993-04-22 20:48:09 UTC
+++ tcpview.h
@@ -97,8 +97,8 @@ void perror();
 void perror();
 #endif
 
-void iprint();         /* print Motif information */
-void eprint();         /* print Motif error */
+void iprint(char *, ...);         /* print Motif information */
+void eprint(char *, ...);         /* print Motif error */
 
 void detail_ether();
 void detail_tcp();
