--- src/xmule.cpp.orig	Tue Sep  9 00:15:19 2003
+++ src/xmule.cpp	Tue Sep  9 00:16:06 2003
@@ -797,7 +797,7 @@
 	delete[] emulesig_path;
 	delete[] xmulesig_path;
 } //End Added By Bouc7
-#if defined(__Linux__)
+#if 0
 #include <execinfo.h>
 #endif
 
@@ -810,7 +810,7 @@
 		theApp.clientudp->Destroy();
 
 	// (stkn) create backtrace
-#if defined(__Linux__)
+#if 0
 	void *bt_array[100];	// 100 should be enough ?!?
 	char **bt_strings;
 	int num_entries;
