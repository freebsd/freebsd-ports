--- modules/atoms/macros/atoms_internals/atomsAUWriteAccess.sci.orig	2010-12-16 23:18:06.000000000 -0800
+++ modules/atoms/macros/atoms_internals/atomsAUWriteAccess.sci	2010-12-16 23:21:49.000000000 -0800
@@ -24,25 +24,11 @@
     atoms_system_directory  = atomsPath("system" ,"allusers");
     atoms_install_directory = atomsPath("install","allusers");
 
-    // Physical test
-
-    if ~ isdir(atoms_system_directory) then
-        if mkdir(atoms_system_directory) <> 1 then
-            return;
-        end
-    end
-
-    if execstr("mputl(""dummy"",atoms_system_directory+""dummy"");","errcatch") == 0 then
+    // Just assume root should install to DATADIR and everyone else should
+    // use ~/.Scilab
+    rep = unix_g("whoami");
+    if rep == "root" then
         res = %T;
-        mdelete(atoms_system_directory+"dummy");
-    else
-        return;
-    end
-
-    if execstr("mputl(""dummy"",atoms_install_directory+""dummy"");","errcatch") <> 0 then
-        res = %F;
-    else
-        mdelete(atoms_install_directory+"dummy");
     end
 
 endfunction
