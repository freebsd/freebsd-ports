--- crm_expandvar.c.orig	Mon Jul 18 14:12:35 2005
+++ crm_expandvar.c	Mon Jul 18 14:12:54 2005
@@ -961,8 +961,6 @@
   long scanbuflen;
   
   long nw_start, nw_len;
-  nw_start = 0;
-  nw_len = 0;
 
   char *mdw;               //  the data window that this var is stored in.
   char *start_ptr;
@@ -971,6 +969,9 @@
   long in_subscript;
 
   long i, j;
+
+  nw_start = 0;
+  nw_len = 0;
 
   if (user_trace)
     fprintf (stderr, "Performing variable restriction.\n");
