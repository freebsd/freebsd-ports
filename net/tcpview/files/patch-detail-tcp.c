--- detail-tcp.c.orig	1993-04-22 20:39:55 UTC
+++ detail-tcp.c
@@ -37,6 +37,7 @@ static char rcsid[] =
 #endif
 
 #include <sys/types.h>
+#include <sys/param.h>
 #include <netinet/in.h>
 #include <netinet/in_systm.h>
 #include <netinet/ip.h>
@@ -82,7 +83,7 @@ u_short length;
   hex( 2, 3 );
 
   bcopy(&tp->th_seq,&seq,4);
-  NTOHL(seq);
+  ntohl(seq);
   printf("Sequence number = %lu\n",seq);
   hex( 4, 7 );
 
@@ -90,7 +91,7 @@ u_short length;
 
   if( flags & TH_ACK ) {
     bcopy(&tp->th_ack,&ack,4);
-    NTOHL(ack);
+    ntohl(ack);
     printf("Acknowledgement number = %lu\n",ack);
     hex( 8, 11);
   }
