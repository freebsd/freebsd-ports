--- unixlib/pop.C.orig	Sun Jun 17 21:07:06 2001
+++ unixlib/pop.C	Sun Jun 17 21:07:27 2001
@@ -53,7 +53,7 @@
 
   if(check_unix_passwd(up.name, password.c_str(), uid, protocol.c_str()))
    {
-    logf.printf("login", "invalid login: \"%s\"", password.c_str());
+    logf.printf("login", "invalid login: \"%s\"", up.name);
     return TRUE;
    }
 
