--- common/client_msgs.h.orig	Tue Oct 28 02:25:14 2003
+++ common/client_msgs.h	Tue Oct 28 02:25:30 2003
@@ -85,7 +85,7 @@
 
 void print_error PROTO((int err_no, char *str));
 
-void print_response PROTO(());
+void print_response PROTO((int resp_no, char *format, ...));
 
 void print_ok PROTO((void));
 
