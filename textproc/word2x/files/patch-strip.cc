--- strip.cc.orig	Sun May  9 23:50:49 1999
+++ strip.cc	Wed Mar 31 21:15:43 2004
@@ -16,9 +16,9 @@
 #ifdef HAVE_CTYPE_H
 #include <ctype.h>
 #endif /* HAVE_CTYPE_H */
-#include <stream.h>
-#include <iostream.h>
-#include <fstream.h>
+#include <iostream>
+#include <fstream>
+using namespace std;
 #include "strip.h"
 #include "tune.h"
 
