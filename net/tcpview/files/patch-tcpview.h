--- tcpview.h.orig	Fri Apr 23 04:48:09 1993
+++ tcpview.h	Tue Oct 28 02:02:49 2003
@@ -97,8 +97,8 @@
 void perror();
 #endif
 
-void iprint();         /* print Motif information */
-void eprint();         /* print Motif error */
+void iprint(char *, ...);         /* print Motif information */
+void eprint(char *, ...);         /* print Motif error */
 
 void detail_ether();
 void detail_tcp();
