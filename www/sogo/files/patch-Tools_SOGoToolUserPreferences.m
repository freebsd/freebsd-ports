--- Tools/SOGoToolUserPreferences.m.orig	2015-09-16 18:41:31 UTC
+++ Tools/SOGoToolUserPreferences.m
@@ -115,7 +115,7 @@ typedef enum
       [theKey caseInsensitiveCompare: @"Vacation"] == NSOrderedSame)
     {
       /* credentials file handling */
-      NSString *credsFilename, *authname, *authpwd;
+      NSString *credsFilename=nil, *authname=nil, *authpwd=nil;
       SOGoCredentialsFile *cf;
 
       credsFilename = [[NSUserDefaults standardUserDefaults] stringForKey: @"p"];
