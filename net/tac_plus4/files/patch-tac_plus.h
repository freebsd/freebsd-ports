--- tac_plus.h.orig	2026-02-10 21:45:32 UTC
+++ tac_plus.h
@@ -450,6 +450,7 @@ int skey_fn(struct authen_data *data);
 int sendauth_fn(struct authen_data *data);
 int sendpass_fn(struct authen_data *data);
 int skey_fn(struct authen_data *data);
+int opie_fn(struct authen_data *data);
 
 /* tac_plus.c */
 void open_logfile(void);
