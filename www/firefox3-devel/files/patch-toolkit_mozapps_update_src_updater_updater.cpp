--- toolkit/mozapps/update/src/updater/updater.cpp.orig	2009-09-16 04:41:19.000000000 +0200
+++ toolkit/mozapps/update/src/updater/updater.cpp	2009-09-18 01:49:47.000000000 +0200
@@ -511,7 +511,7 @@
   struct stat ss;
 
   AutoFile sfile = NS_tfopen(spath, NS_T("rb"));
-  if (sfile == NULL || fstat(fileno(sfile), &ss)) {
+  if (sfile == NULL || fstat(fileno((FILE*)sfile), &ss)) {
     LOG(("copy_file: failed to open or stat: %p," LOG_S ",%d\n", sfile.get(), spath, errno));
     return READ_ERROR;
   }
@@ -1660,7 +1660,7 @@
     return READ_ERROR;
 
   struct stat ms;
-  rv = fstat(fileno(mfile), &ms);
+  rv = fstat(fileno((FILE*)mfile), &ms);
   if (rv)
     return READ_ERROR;
 
