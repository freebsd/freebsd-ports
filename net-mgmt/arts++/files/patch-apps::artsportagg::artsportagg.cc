--- ./apps/artsportagg/artsportagg.cc.orig	Mon Oct  2 13:05:12 2000
+++ ./apps/artsportagg/artsportagg.cc	Wed Sep 25 16:38:09 2002
@@ -50,14 +50,19 @@
 #include <errno.h>
 }
 
-#include <fstream.h>
-#include <string>
-
 #include "ArtsPortTableAggregator.hh"
 #include "Arts.hh"
 #include "ArtsPortTableAggregatorMapKey.hh"
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
