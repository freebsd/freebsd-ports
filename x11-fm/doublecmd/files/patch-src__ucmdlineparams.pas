--- ./src/ucmdlineparams.pas.orig	2013-06-08 17:54:12.000000000 +0200
+++ ./src/ucmdlineparams.pas	2013-06-30 21:42:23.609940000 +0200
@@ -20,10 +20,7 @@
 implementation
 
 uses
-  {$IF DEFINED(NIGHTLY_BUILD)}
-  uOSUtils,
-  {$ENDIF}
-  Forms, Dialogs, SysUtils, uDCUtils, uGlobsPaths, getopts, uDebug, uLng;
+  uOSUtils, Forms, Dialogs, SysUtils, uDCUtils, uGlobsPaths, getopts, uDebug, uLng;
 
 procedure ProcessCommandLineParams;
 var
