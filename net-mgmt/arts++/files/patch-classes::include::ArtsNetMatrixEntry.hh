--- ./classes/include/ArtsNetMatrixEntry.hh.orig	Mon Oct  2 13:05:17 2000
+++ ./classes/include/ArtsNetMatrixEntry.hh	Wed Sep 25 16:38:10 2002
@@ -51,9 +51,10 @@
 }
 
 #ifdef HAVE_IOSTREAM
-  #include <iostream>
+# include <iostream>
+  using namespace std;
 #else
-  #include <iostream.h>
+# include <iostream.h>
 #endif
 
 #ifdef HAVE_IOMANIP
