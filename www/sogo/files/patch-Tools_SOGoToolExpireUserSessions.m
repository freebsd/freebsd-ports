--- Tools/SOGoToolExpireUserSessions.m.orig	2015-09-16 18:41:31 UTC
+++ Tools/SOGoToolExpireUserSessions.m
@@ -143,7 +143,7 @@
   else
   {
     if (verbose)
-      NSLog(@"No session to remove", sessionsToDelete);
+      NSLog(@"No session to remove");
   }
 
   [cm releaseChannel: channel];
