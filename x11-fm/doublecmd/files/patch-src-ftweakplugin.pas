--- src/ftweakplugin.pas	2012-12-12 14:39:03.000000000 -0500
+++ src/ftweakplugin.pas	2012-12-12 14:39:40.000000000 -0500
@@ -276,7 +276,7 @@
 
 procedure TfrmTweakPlugin.FormCreate(Sender: TObject);
 begin
-  {$if (lcl_release) < 31}
+  {$if (lcl_major < 1) and (lcl_release < 31)}
   nbTweakAll.ShowTabs := False;
   nbTweakAll.TabStop := True;
   {$endif}
