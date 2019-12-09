--- UI/MailPartViewers/UIxMailPartEncryptedViewer.m	2019-12-09 16:41:38.841316000 -0500
+++ UI/MailPartViewers/UIxMailPartEncryptedViewer.m	2019-12-09 16:42:17.792368000 -0500
@@ -171,13 +171,13 @@
       if (err)
         {
 #ifdef HAVE_GNUTLS
-          const char* sslError;
+          NSString* sslError;
 	  ERR_load_crypto_strings();
           SSL_load_error_strings();
           sslError = ERR_reason_error_string(err);
           validationMessage = [[self labelForKey: [NSString stringWithUTF8String: sslError ? sslError : @"No error information available"]] retain];
 #elif OPENSSL_VERSION_NUMBER < 0x10100000L
-          const char* sslError;
+          NSString* sslError;
 	  ERR_load_crypto_strings();
           SSL_load_error_strings();
           sslError = ERR_reason_error_string(err);
