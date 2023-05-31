--- SoObjects/SOGo/SOGoGCSFolder.m	2023-05-31 09:06:17.230915000 -0500
+++ SoObjects/SOGo/SOGoGCSFolder.m	2023-05-31 09:07:25.625868000 -0500
@@ -150,7 +150,7 @@
   if ([pathElements count] > 1)
     ocsName = [pathElements objectAtIndex: 1];
   else
-    ocsName = [[context request] isMacOSXVenturaCalendarApp] ? @"Personal" : @"personal";
+    ocsName = [[localContext request] isMacOSXVenturaCalendarApp] ? @"Personal" : @"personal";
 
   path = [NSString stringWithFormat: @"/Users/%@/%@/%@",
 		   login, [pathElements objectAtIndex: 0], ocsName];
