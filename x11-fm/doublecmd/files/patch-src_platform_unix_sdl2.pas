--- src/platform/unix/sdl2.pas.orig	2025-01-24 23:49:21 UTC
+++ src/platform/unix/sdl2.pas
@@ -122,7 +122,7 @@ begin
       Exit(False);
     end;
   end;
-  Result:= BeginThread(@Play, AudioData) > 0;
+  Result:= BeginThread(@Play, AudioData) > TThreadID(0);
 end;
 
 const
