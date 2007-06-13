--- print-tcp.c.orig	Wed Jun 13 22:18:16 2007
+++ print-tcp.c	Wed Jun 13 22:18:32 2007
@@ -410,6 +410,8 @@
 
 /* assemble a single bidirectional stream */
 
+static int check_frags();
+
 static void assemble( seq, len, data, syn, srcx )
 u_long seq, len, srcx;
 u_char *data;
@@ -418,7 +420,6 @@
   int i,j,first=0;
   u_long newptr;
   struct tcp_frag *t;
-  static int check_frags();
 
 /*  fprintf(stderr,"assemble seq=%d  len=%d  syn=%d  src=%lx\n",seq,len,syn,srcx); */
   i = -1;
