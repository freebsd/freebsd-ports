--- ./classes/include/ArtsPortMatrixEntry.hh.orig	Mon Oct  2 13:05:18 2000
+++ ./classes/include/ArtsPortMatrixEntry.hh	Wed Sep 25 16:38:10 2002
@@ -50,15 +50,16 @@
 }
 
 #ifdef HAVE_IOSTREAM
-  #include <iostream>
+#  include <iostream>
+   using namespace std;
 #else
-  #include <iostream.h>
+#  include <iostream.h>
 #endif
 
 #ifdef HAVE_IOMANIP
-  #include <iomanip>
+#  include <iomanip>
 #else
-  #include <iomanip.h>
+#  include <iomanip.h>
 #endif
 
 //---------------------------------------------------------------------------
