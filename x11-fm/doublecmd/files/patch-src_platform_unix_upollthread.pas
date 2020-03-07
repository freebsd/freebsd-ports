--- src/platform/unix/upollthread.pas.orig	2019-12-08 11:40:55 UTC
+++ src/platform/unix/upollthread.pas
@@ -161,7 +161,7 @@ begin
   // Create pipe for user triggered fake event
   FEventPipe[0] := -1;
   FEventPipe[1] := -1;
-  if fpPipe(FEventPipe) < 0 then
+  if fpPipe(FEventPipe, 0) < 0 then
     Print(SysErrorMessage(fpGetErrNo))
   else begin
     // Set both ends of pipe non blocking
