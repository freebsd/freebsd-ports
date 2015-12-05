--- packages/uuid/fpmake.pp.orig	2015-01-05 19:27:06.000000000 +0000
+++ packages/uuid/fpmake.pp
@@ -18,7 +18,7 @@ begin
 {$endif ALLPACKAGES}
     P.Version:='3.0.1';
     P.SourcePath.Add('src');
-    P.OSes := [linux];
+    P.OSes := [linux,dragonfly,freebsd];
     P.Dependencies.Add('rtl-extra');
 
     T:=P.Targets.AddUnit('libuuid.pp');
