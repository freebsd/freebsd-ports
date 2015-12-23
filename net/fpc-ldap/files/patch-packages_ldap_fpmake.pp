--- packages/ldap/fpmake.pp.orig	2015-01-05 19:27:06.000000000 +0000
+++ packages/ldap/fpmake.pp
@@ -23,7 +23,7 @@ begin
     P.Email := '';
     P.Description := 'Header to openldap, a library that to access directory services';
     P.NeedLibC:= true;  // true for headers that indirectly link to libc?
-    P.OSes := [linux];
+    P.OSes := [linux,dragonfly,freebsd];
 
 
     P.SourcePath.Add('src');
