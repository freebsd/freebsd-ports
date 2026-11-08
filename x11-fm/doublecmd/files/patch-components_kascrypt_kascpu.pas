--- components/kascrypt/kascpu.pas.orig	2026-07-18 09:01:48 UTC
+++ components/kascrypt/kascpu.pas
@@ -111,7 +111,7 @@ initialization
 end;
 
 initialization
-  Initialize;
+//  Initialize;
 
 {$ELSEIF DEFINED(CPUX86_64)}
 
