--- src/xmule.cpp.orig	Mon Aug 11 14:38:14 2003
+++ src/xmule.cpp	Mon Aug 11 14:38:27 2003
@@ -763,7 +763,7 @@
 	delete[] xmulesig_path;
 }
 
-#if defined(__Linux__)
+#if 0
 #include <execinfo.h>
 #endif
 
@@ -776,7 +776,7 @@
     	theApp.clientudp->Destroy();
 
     // (stkn) create backtrace
-#if defined(__Linux__)
+#if 0
     void * bt_array[100]; // 100 should be enough ?!?
     char ** bt_strings;
     int num_entries;
