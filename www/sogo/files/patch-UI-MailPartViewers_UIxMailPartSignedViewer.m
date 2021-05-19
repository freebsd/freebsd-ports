--- UI/MailPartViewers/UIxMailPartSignedViewer.m	2021-03-30 21:00:31.000000000 -0500
+++ UI/MailPartViewers/UIxMailPartSignedViewer.m	2021-04-16 16:02:22.004059000 -0500
@@ -169,13 +169,13 @@
       if (err)
         {
 #ifdef HAVE_GNUTLS
-          const char* sslError;
+          NSString* sslError;
 	  ERR_load_crypto_strings();
           SSL_load_error_strings();
           sslError = ERR_reason_error_string(err);
           validationMessage = [[self labelForKey: [NSString stringWithUTF8String: sslError ? sslError : @"Digital signature is not valid"]] retain];
 #elif OPENSSL_VERSION_NUMBER < 0x10100000L
-          const char* sslError;
+          NSString* sslError;
 	  ERR_load_crypto_strings();
           SSL_load_error_strings();
           sslError = ERR_reason_error_string(err);
