--- src/ftrack.cpp.orig	Fri Apr 26 20:59:40 2002
+++ src/ftrack.cpp	Wed Jan  5 21:39:27 2005
@@ -53,7 +53,7 @@
 //                         Signals catch functions
 // --------------------------------------------------------------------
 void AbrtHndl(int Sign) {
-fstream fh ("FTrack.err", ios::append);
+fstream fh ("FTrack.err", ios::app);
 
    cerr << "Internal Error!!! Please, read report.err in documentation.\n";
    cerr << "---------------------------------------\n";
