--- ./classes/include/ArtsIpPathEntry.hh.orig	Mon Oct  2 13:05:16 2000
+++ ./classes/include/ArtsIpPathEntry.hh	Wed Sep 25 16:38:10 2002
@@ -54,6 +54,7 @@
 
 #ifdef HAVE_IOSTREAM
   #include <iostream>
+  using namespace std;
 #else
   #include <iostream.h>
 #endif
