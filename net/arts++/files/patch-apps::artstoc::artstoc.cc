--- ./apps/artstoc/artstoc.cc.orig	Mon Oct  2 13:05:13 2000
+++ ./apps/artstoc/artstoc.cc	Wed Sep 25 16:38:09 2002
@@ -49,14 +49,19 @@
 #include <errno.h>
 }
 
-#include <fstream.h>
-#include <string>
-
 #include "Arts.hh"
 #include "ArtsTimeIntervalSelectionSet.hh"
 #include "ArtsPackageVersion.hh"
 #ifndef NDEBUG
   #include "ArtsDebug.hh"
+#endif
+
+#ifdef HAVE_FSTREAM
+# include <fstream>
+# include <iterator>
+  using namespace std;
+#else
+# include <fstream.h>
 #endif
 
 extern char *tzname[2];
