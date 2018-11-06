--- UI/MailPartViewers/UIxMailPartSignedViewer.m	2018-10-23 14:22:36.000000000 -0500
+++ UI/MailPartViewers/UIxMailPartSignedViewer.m	2018-11-06 13:02:05.090224000 -0500
@@ -169,13 +169,13 @@
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
