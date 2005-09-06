--- src/folder.cxx.orig	Wed Aug 17 10:15:03 2005
+++ src/folder.cxx	Wed Aug 17 10:15:29 2005
@@ -1382,7 +1382,7 @@
 }
 folders_functions::~folders_functions()
 { }
-void folders_functions::call(enum CALLTYPE m=FOLDERS)
+void folders_functions::call(enum CALLTYPE m)
 {
 	if (func)
 		func();
