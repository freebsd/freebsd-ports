--- src/foptions.pas	2012-12-12 14:41:07.000000000 -0500
+++ src/foptions.pas	2012-12-12 14:41:39.000000000 -0500
@@ -580,7 +580,7 @@
 
   // Below needed until after we switch to Lazarus 0.9.31.
   nbNotebook.TabStop := True;
-  {$if (lcl_release) < 31}
+  {$if (lcl_major < 1) and (lcl_release < 31)}
   nbNotebook.ShowTabs := False;
   nbNotebook.OnPageChanged := @nbNotebookPageChanged;
   {$endif}
