--- Tools/SOGoToolUpdateSecret.m.orig	2026-03-30 08:52:39 UTC
+++ Tools/SOGoToolUpdateSecret.m
@@ -266,8 +266,6 @@ - (BOOL) updateSecretFromEncryptedData: (NSString*) ne
       [source synchronize];
     }
   }
-
-  return rc;
 }
 
 - (BOOL) updateToPlainData: (NSString*) oldSecret
