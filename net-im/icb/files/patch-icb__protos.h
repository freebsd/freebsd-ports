--- icb/protos.h.orig	2000-12-15 12:21:04.000000000 +0900
+++ icb/protos.h	2012-10-25 18:14:24.000000000 +0900
@@ -171,7 +171,7 @@
 void readlineinit (void);
 
 /* oset.c */
-void restrict (void);
+void icb_restrict (void);
 
 /* send.c */
 void send_command (char* cmd, char* arg);
