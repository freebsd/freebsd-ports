--- tac_plus.h.orig	2013-04-13 13:45:20.000000000 +0400
+++ tac_plus.h	2013-04-13 13:50:14.000000000 +0400
@@ -452,6 +452,7 @@
 int sendauth_fn(struct authen_data *data);
 int sendpass_fn(struct authen_data *data);
 int skey_fn(struct authen_data *data);
+int opie_fn(struct authen_data *data);
 
 /* tac_plus.c */
 void open_logfile(void);
