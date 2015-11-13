--- Tools/SOGoToolRenameUser.m.orig	2015-09-16 18:41:31 UTC
+++ Tools/SOGoToolRenameUser.m
@@ -148,7 +148,7 @@
   if (sqlError)
     {
       [ac rollbackTransaction];
-      NSLog([sqlError reason]);
+      NSLog(@"%@", [sqlError reason]);
     }
   else
     rc = [ac commitTransaction];
@@ -201,7 +201,7 @@
   if (sqlError)
     {
       [ac rollbackTransaction];
-      NSLog([sqlError reason]);
+      NSLog(@"%@", [sqlError reason]);
     }
   else
     rc = [ac commitTransaction];
