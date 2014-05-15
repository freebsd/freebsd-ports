--- iface.c.orig	2012-08-10 19:40:14.000000000 +0400
+++ iface.c	2014-05-07 18:17:01.000000000 +0400
@@ -47,7 +46,7 @@
 extern int g_med_cutoff ;
 extern char *g_att_epsilon;
 
-extern int foma_net_print(struct fsm *net, gzFile *outfile);
+extern int foma_net_print(struct fsm *net, gzFile outfile);
 
 static char *sigptr(struct sigma *sigma, int number);
 static int print_dot(struct fsm *net, char *filename);
@@ -999,7 +998,7 @@
 }
 
 void iface_save_stack(char *filename) {
-    gzFile *outfile;
+    gzFile outfile;
     struct stack_entry *stack_ptr;
 
     if (iface_stack_check(1)) {
