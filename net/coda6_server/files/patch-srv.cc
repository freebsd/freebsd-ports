--- coda-src/vice/srv.cc.orig	Fri Sep  3 16:22:14 2004
+++ coda-src/vice/srv.cc	Tue Nov 16 22:19:04 2004
@@ -1204,6 +1204,7 @@
 void SwapLog()
 {
     struct timeval tp;
+    time_t start;
 
     /* Need to chdir() again, since salvage may have put me elsewhere */
     if(chdir(vice_file("srv"))) {
@@ -1216,7 +1217,8 @@
     
     /* Print out time/date, since date info has "scrolled off" */
     TM_GetTimeOfDay(&tp, 0);
-    SLog(0, "Coda Vice, version " PACKAGE_VERSION "\tlog started at %s", ctime(&tp.tv_sec));
+    start=tp.tv_sec;
+    SLog(0, "Coda Vice, version " PACKAGE_VERSION "\tlog started at %s", ctime(&start));
 }
 
 static void FileMsg()
