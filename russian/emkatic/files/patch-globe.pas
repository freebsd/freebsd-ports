--- globe.pas	2022-02-02 23:19:19.035871000 -0500
+++ globe.pas	2022-02-02 23:19:31.522474000 -0500
@@ -26,7 +26,7 @@
 
 uses
   Classes,SysUtils,Forms,Controls,ComCtrls,StdCtrls,Buttons,Graphics,
-  SynEdit,Math,Serial,InstrSet,DecNorm,eMKaticIPC,ResStr;
+  SynEdit,SynEditTypes,Math,Serial,InstrSet,DecNorm,eMKaticIPC,ResStr;
 
 type
   TAltMod = (amUnknown,amNoSave,amTemporary,amShow,amClean,amDefault,
