--- modules/atoms/macros/atoms_gui/atomsGui.sci.orig	2010-12-15 02:20:51.000000000 -0800
+++ modules/atoms/macros/atoms_gui/atomsGui.sci	2010-12-15 02:21:41.000000000 -0800
@@ -20,7 +20,7 @@
 
     if errStatus<>0 | size(allModules, "*") == 0 then
         if size(atomsRepositoryList(),"*") > 0 then
-            messagebox(gettext("No ATOMS module is available. Please, check your Internet connection."), gettext("ATOMS error"), "error");
+            messagebox(gettext("ATOMS is not available for FreeBSD at this time."), gettext("ATOMS error"), "error");
         else
             messagebox(gettext("No ATOMS module is available: your repository list is empty."), gettext("ATOMS error"), "error");
         end
