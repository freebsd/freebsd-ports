--- ./classes/include/ArtsHeader.hh.orig	Mon Oct  2 13:05:15 2000
+++ ./classes/include/ArtsHeader.hh	Wed Sep 25 16:46:54 2002
@@ -50,11 +50,13 @@
 #include "caida_t.h"
 }
 
-#include <ostream.h>
-#ifdef HAVE_IOMANIP
-  #include <iomanip>
+#ifdef HAVE_OSTREAM
+#  include <ostream>
+#  include <iomanip>
+   using namespace std;
 #else
-  #include <iomanip.h>
+#  include <ostream.h>
+#  include <iomanip.h>
 #endif
 
 //---------------------------------------------------------------------------
