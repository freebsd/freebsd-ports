--- storage/e-folder-exchange.c.orig	Tue Jan 25 21:31:32 2005
+++ storage/e-folder-exchange.c	Tue Jan 25 21:31:52 2005
@@ -689,11 +689,12 @@
 void
 e_folder_exchange_unsubscribe (EFolder *folder)
 {
+	E2kContext *ctx;
 	g_return_if_fail (E_IS_FOLDER_EXCHANGE (folder));
 
 	/* FIXME : This is a hack as of now. The free_folder in mail-stub
 	gets called when we are in offline and the context is NULL then. */
-	E2kContext *ctx = E_FOLDER_EXCHANGE_CONTEXT (folder);
+	ctx = E_FOLDER_EXCHANGE_CONTEXT (folder);
 	if (ctx) {
 		e2k_context_unsubscribe (E_FOLDER_EXCHANGE_CONTEXT (folder),
 					 E_FOLDER_EXCHANGE_URI (folder));
