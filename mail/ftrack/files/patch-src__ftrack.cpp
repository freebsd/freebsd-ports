--- src/ftrack.cpp.orig	Fri Aug 19 17:58:00 2005
+++ src/ftrack.cpp	Fri Aug 19 17:59:25 2005
@@ -42,8 +42,8 @@
 #include "parsetpl.hpp"
 #include "tmstamp.hpp"
 #include "script.hpp"
-#include <iostream.h>
-#include <fstream.h>
+#include <iostream>
+#include <fstream>
 #include <smapi/msgapi.h>
 
 static struct utimbuf ut;
@@ -53,7 +53,7 @@
 //                         Signals catch functions
 // --------------------------------------------------------------------
 void AbrtHndl(int Sign) {
-fstream fh ("FTrack.err", ios::append);
+fstream fh ("FTrack.err", ios::app);
 
    cerr << "Internal Error!!! Please, read report.err in documentation.\n";
    cerr << "---------------------------------------\n";
