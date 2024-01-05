--- components/virtualterminal/source/unix/vtemupty.pas.orig	2024-01-04 17:04:32 UTC
+++ components/virtualterminal/source/unix/vtemupty.pas
@@ -171,7 +171,7 @@ end;
 constructor TPtyDevice.Create(AOwner: TComponent);
 begin
   inherited Create(AOwner);
-  if fpPipe(FEventPipe) < 0 then
+  if fpPipe(FEventPipe,0) < 0 then
     WriteLn(SysErrorMessage(fpGetErrNo))
   else begin
     // Set both ends of pipe non blocking
