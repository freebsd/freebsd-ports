--- nntp.c.orig	Mon Aug  2 15:11:21 2004
+++ nntp.c	Mon Aug  2 15:12:31 2004
@@ -1064,13 +1064,12 @@
 {
   char buf[LONG_STRING];
   CONNECTION* conn;
-  CONNECTION* tmp;
 
   conn = mutt_socket_head ();
 
   while (conn)
   {
-    tmp = conn;
+    CONNECTION *next = conn->next;
 
     if (conn->account.type == M_ACCT_TYPE_NNTP)
     {
@@ -1079,11 +1078,10 @@
       mutt_socket_readln (buf, sizeof (buf), conn);
       mutt_clear_error ();
       mutt_socket_close (conn);
-
-      mutt_socket_free (tmp);
+      mutt_socket_free (conn);
     }
 
-    conn = conn->next;
+    conn = next;
   }
 }
 
