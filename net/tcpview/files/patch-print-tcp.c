--- print-tcp.c.orig	1993-04-22 20:40:28 UTC
+++ print-tcp.c
@@ -410,6 +410,8 @@ static u_long src[2] = { 0, 0 };
 
 /* assemble a single bidirectional stream */
 
+static int check_frags();
+
 static void assemble( seq, len, data, syn, srcx )
 u_long seq, len, srcx;
 u_char *data;
@@ -418,7 +420,6 @@ int syn;
   int i,j,first=0;
   u_long newptr;
   struct tcp_frag *t;
-  static int check_frags();
 
 /*  fprintf(stderr,"assemble seq=%d  len=%d  syn=%d  src=%lx\n",seq,len,syn,srcx); */
   i = -1;
