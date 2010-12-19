--- modules/dynamic_link/macros/ilib_gen_Make_unix.sci.orig	2010-11-24 00:50:36.000000000 -0800
+++ modules/dynamic_link/macros/ilib_gen_Make_unix.sci	2010-12-15 05:04:30.000000000 -0800
@@ -64,22 +64,7 @@
     originPath  = pwd();
     linkBuildDir    = TMPDIR;
     commandpath = SCI+"/modules/dynamic_link/src/scripts";
-    [fd,ierr] = mopen(commandpath+"/write.test","w+");
-
-    if (ierr<>0) then
-      writePerm=%F
-    else
-      writePerm=%T
-      mclose(fd)
-      mdelete(commandpath+"/write.test");
-    end
-
-    if (writePerm == %T & ( fileinfo(commandpath+"/Makefile.orig") == [] | fileinfo(commandpath+"/libtool") == [] )) then
-      // We have write permission on the scilab tree, then generate the stuff into the directory in order to avoid the configure each time.
-        generateConfigure(commandpath);
-    end
-
-
+    
     // Copy files => linkBuildDir
     chdir(linkBuildDir);
 
@@ -178,7 +163,7 @@
         end
     end
 
-    if ldflags <> '' | cflags <> '' | fflags <> '' | cc <> '' | fileinfo(commandpath+"/Makefile.orig") == [] | fileinfo(commandpath+"/libtool") == [] then
+    if %T then
         // Makefile.orig doesn't exists or may be invalid regarding the flags
         // run the ./configure with the flags
 
@@ -274,4 +259,4 @@
     end
 
 endfunction
-//=============================================================================
\ No newline at end of file
+//=============================================================================
