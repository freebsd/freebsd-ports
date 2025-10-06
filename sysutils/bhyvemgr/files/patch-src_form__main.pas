--- src/form_main.pas.orig	2025-10-06 18:41:10 UTC
+++ src/form_main.pas
@@ -219,7 +219,7 @@ begin
   DebugLogger.CloseLogFileBetweenWrites:= true;
   DebugLogger.LogName:= GetUserDir + '.config/bhyvemgr/bhyvemgr.log';
 
-  DebugLn('['+FormatDateTime('DD-MM-YYYY HH:NN:SS', Now)+'] : '=debugln_bhyve_started);
+  DebugLn('['+FormatDateTime('DD-MM-YYYY HH:NN:SS', Now)+'] : '+debugln_bhyve_started);
 
   FormSettings:= TFormSettings.Create(FormBhyveManager);
   FormAbout:= TFormAbout.Create(FormBhyveManager);
@@ -4009,7 +4009,7 @@ begin
   if (Assigned(DeviceSettingsTreeView.Items.FindTopLvlNode('Display')))
      and (DeviceSettingsTreeView.Items.FindTopLvlNode('Display').Count = 1) then
   begin
-    DisplayNode:=DeviceSettingsTreeView.Items.TopLvlItems[2].Items[0];
+    DisplayNode:=DeviceSettingsTreeView.Items.FindTopLvlNode('Display').Items[0];
     DisplayDevice:=TDisplayDeviceClass(DisplayNode.Data);
     VncConnect(DisplayDevice.tcp, TVirtualMachineClass(VirtualMachinesTreeView.Selected.Data).name);
   end;
@@ -4163,7 +4163,8 @@ begin
       SpeedButtonRemoveVm.Enabled:=False;
       SpeedButtonReloadVmConfig.Enabled:=False;
 
-      if DeviceSettingsTreeView.Items.TopLvlItems[2].Count = 1 then
+      if (Assigned(DeviceSettingsTreeView.Items.FindTopLvlNode('Display')))
+            and (DeviceSettingsTreeView.Items.FindTopLvlNode('Display').Count = 1) then
         SpeedButtonVncVm.Enabled:=True
       else
         SpeedButtonVncVm.Enabled:=False;
