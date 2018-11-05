--- UI/MailPartViewers/UIxMailPartSignedViewer.m	2018-11-04 23:25:20.140369000 -0500
+++ UI/MailPartViewers/UIxMailPartSignedViewer.m	2018-11-04 23:28:00.684899000 -0500
@@ -173,15 +173,15 @@
 	  ERR_load_crypto_strings();
           SSL_load_error_strings();
           sslError = ERR_reason_error_string(err);
-          validationMessage = [[self labelForKey: [NSString stringWithUTF8String: sslError ? sslError : @"No error information available"]] retain];
+          validationMessage = [[self labelForKey: [NSString stringWithUTF8String: sslError ? sslError : "No error information available"]] retain];
 #elif OPENSSL_VERSION_NUMBER < 0x10100000L
           const char* sslError;
 	  ERR_load_crypto_strings();
           SSL_load_error_strings();
           sslError = ERR_reason_error_string(err);
-          validationMessage = [[self labelForKey: [NSString stringWithUTF8String: sslError ? sslError : @"No error information available"]] retain];
+          validationMessage = [[self labelForKey: [NSString stringWithUTF8String: sslError ? sslError : "No error information available"]] retain];
 #else
-	  validationMessage = [[self labelForKey: @"No error information available"] retain];
+	  validationMessage = [[self labelForKey: "No error information available"] retain];
 #endif /* HAVE_GNUTLS */
       }
     }
