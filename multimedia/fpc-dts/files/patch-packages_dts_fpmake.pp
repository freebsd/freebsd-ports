--- packages/dts/fpmake.pp.orig	2015-01-05 19:27:06 UTC
+++ packages/dts/fpmake.pp
@@ -24,7 +24,7 @@ begin
     P.Email := '';
     P.Description := 'a low-level interface to decoding audio frames encoded using DTS Coherent Acoustics';
     P.NeedLibC:= true;
-    P.OSes := [linux];
+    P.OSes := [linux,dragonfly,freebsd];
 
     P.SourcePath.Add('src');
 
