--- SoObjects/SOGo/SOGoMailer.m	2025-03-25 23:34:20.921308000 -0700
+++ SoObjects/SOGo/SOGoMailer.m	2025-03-25 23:34:50.890963000 -0700
@@ -325,7 +325,7 @@
           {
             login = [currentAcount objectForKey: @"userName"];
             password = [currentAcount objectForKey: @"password"];
-            smtpAuthMethod = "plain"; //Only support plain for auxiliary account
+            smtpAuthMethod = @"plain"; //Only support plain for auxiliary account
           }
           else
           {
