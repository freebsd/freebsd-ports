--- error.h.orig	2015-01-26 09:59:47 UTC
+++ error.h
@@ -229,8 +229,8 @@ struct diag_dgram {
 } ;
 
 extern sig_atomic_t diag_in_handler;
-extern int diag_immediate_msg;
-extern int diag_immediate_exit;
+extern sig_atomic_t diag_immediate_msg;
+extern sig_atomic_t diag_immediate_exit;
 
 extern void diag_set(char what, const char *arg);
 extern void diag_set_int(char what, int arg);
