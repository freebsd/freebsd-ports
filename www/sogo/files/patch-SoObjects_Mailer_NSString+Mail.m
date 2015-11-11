--- SoObjects/Mailer/NSString+Mail.m.orig	2015-09-16 18:41:30 UTC
+++ SoObjects/Mailer/NSString+Mail.m
@@ -533,7 +533,7 @@
   messageID = [NSMutableString string];
   [messageID appendFormat: @"<%@", [SOGoObject globallyUniqueObjectId]];
   pGUID = [[NSProcessInfo processInfo] globallyUniqueString];
-  [messageID appendFormat: @"@%u>", [pGUID hash]];
+  [messageID appendFormat: @"@%u>", (unsigned int)[pGUID hash]];
 
   return [messageID lowercaseString];
 }
