--- sn_analyse.c.orig	2013-10-15 18:31:28.000000000 +1100
+++ sn_analyse.c	2013-10-15 18:32:24.000000000 +1100
@@ -10,7 +10,7 @@
   {
   if(finish!=TCP_FINISH) 
     if((dummy_pointer=add_dynam(filename, TCP, 0,ntohl(tcphead.seq_nr),info.DATA_len))==NULL)
-	return;
+	return NULL;
   };
 
 if(finish==TCP_FINISH)                      /* let's reset the connection */
@@ -26,7 +26,7 @@
   if(dummy&SYN)	print_conn(filename,"Connection initiated. (SYN)");
   if(dummy&FIN) print_conn(filename,"Connection ending. (FIN)");
   if(dummy&RST) print_conn(filename,"Connection reset. (RST)");
-  return;
+  return NULL;
   };
 
 data = sp+PROTO_HEAD+info.IP_len+info.TCP_len;
@@ -40,7 +40,7 @@
     };
   };
 
-if((dummy&FIN)||(dummy&RST)) return; /* needed, cauz entry don't exist  */  
+if((dummy&FIN)||(dummy&RST)) return NULL; /* needed, cauz entry don't exist  */  
 
 /*** TELNET *****************************************************************/
 if(LOGPARAM & LOGPARAM_TELNET)         
@@ -197,5 +197,5 @@
   if(ntohl(tcphead.seq_nr)>dummy_pointer->exp_seq)
     dummy_pointer->exp_seq=ntohl(tcphead.seq_nr)+info.DATA_len;
   }
-return;
-return;  /* DON'T FORGET THEM!!!! */
+return NULL;
+return NULL;  /* DON'T FORGET THEM!!!! */
