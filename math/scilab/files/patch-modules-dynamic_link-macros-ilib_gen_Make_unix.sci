--- ./modules/dynamic_link/macros/ilib_gen_Make_unix.sci.orig	2014-04-11 09:51:43.000000000 +0000
+++ ./modules/dynamic_link/macros/ilib_gen_Make_unix.sci	2014-07-24 23:46:32.896279292 +0000
@@ -65,20 +65,6 @@
     linkBuildDir    = TMPDIR+"/"+libname;
     mkdir(linkBuildDir);
     commandpath = SCI+"/modules/dynamic_link/src/scripts";
-    [fd,ierr] = mopen(commandpath+"/write.test","w+");
-
-    if (ierr<>0) then
-        writePerm=%F
-    else
-        writePerm=%T
-        mclose(fd)
-        mdelete(commandpath+"/write.test");
-    end
-
-    if (writePerm == %T & ( fileinfo(commandpath+"/Makefile.orig") == [] | fileinfo(commandpath+"/libtool") == [] )) then
-        // We have write permission on the scilab tree, then generate the stuff into the directory in order to avoid the configure each time.
-        generateConfigure(commandpath);
-    end
 
 
     // Copy files => linkBuildDir
@@ -187,7 +173,7 @@
         end
     end
 
-    if ldflags <> "" | cflags <> "" | fflags <> "" | cc <> "" | fileinfo(commandpath+"/Makefile.orig") == [] | fileinfo(commandpath+"/libtool") == [] then
+    if %T then
         // Makefile.orig doesn't exists or may be invalid regarding the flags
         // run the ./configure with the flags
 
