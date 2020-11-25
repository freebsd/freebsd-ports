--- packages/libvlc/fpmake.pp	2017-09-02 11:48:24.000000000 -0500
+++ packages/libvlc/fpmake.pp	2017-12-12 12:19:09.246128000 -0500
@@ -15,15 +15,15 @@
 {$ifdef ALLPACKAGES}
     P.Directory:=ADirectory;
 {$endif ALLPACKAGES}
-    P.OSes := [win32, win64, linux, freebsd];
+    P.OSes := [win32, win64, linux, dragonfly, freebsd];
     P.Dependencies.Add('fcl-base');
     P.Version:='3.2.0';
     P.License := 'LGPL with modification';
     P.HomepageURL := 'www.freepascal.org';
     P.Email := 'michael@freepascal.org';
     P.Description := 'VLC library (version 2 or higher) interface and component.';
-    T:=P.Targets.AddUnit('src/libvlc.pp',[linux,win32,win64]);
-    T:=P.Targets.AddUnit('src/vlc.pp',[linux,win32,win64]);
+    T:=P.Targets.AddUnit('src/libvlc.pp',[linux,win32,win64,dragonfly,freebsd]);
+    T:=P.Targets.AddUnit('src/vlc.pp',[linux,win32,win64,dragonfly,freebsd]);
     with T.Dependencies do
       begin
       AddUnit('libvlc');
