--- tac_plus.h.orig	2012-04-10 19:38:45 UTC
+++ tac_plus.h
@@ -452,6 +452,7 @@ int enable_fn(struct authen_data *data);
 int sendauth_fn(struct authen_data *data);
 int sendpass_fn(struct authen_data *data);
 int skey_fn(struct authen_data *data);
+int opie_fn(struct authen_data *data);
 
 /* tac_plus.c */
 void open_logfile(void);
