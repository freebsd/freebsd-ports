--- ./classes/include/ArtsPrimitive.hh.orig	Mon Oct  2 13:05:19 2000
+++ ./classes/include/ArtsPrimitive.hh	Wed Sep 25 16:38:10 2002
@@ -43,13 +43,19 @@
 #ifndef _ARTSPRIMITIVE_HH_
 #define _ARTSPRIMITIVE_HH_
 
-#include <iostream.h>
 
 extern "C" {
+#include "artslocal.h"
 #include "caida_t.h"
 #include <unistd.h>
 }
 
+#ifdef HAVE_IOSTREAM
+# include <iostream>
+ using namespace std;
+#else
+# include <iostream.h>
+#endif
 //---------------------------------------------------------------------------
 //  class ArtsPrimitive
 //---------------------------------------------------------------------------
