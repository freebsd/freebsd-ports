--- ./apps/artsnexthopagg/artsnexthopagg.cc.orig	Mon Oct  2 13:05:12 2000
+++ ./apps/artsnexthopagg/artsnexthopagg.cc	Wed Sep 25 16:38:09 2002
@@ -50,14 +50,21 @@
 #include <errno.h>
 }
 
-#include <fstream.h>
-#include <string>
-
 #include "ArtsFileUtil.hh"
 #include "ArtsPackageVersion.hh"
 #ifndef NDEBUG
   #include "ArtsDebug.hh"
 #endif
+
+#ifdef HAVE_FSTREAM
+# include <fstream>
+# include <iterator>
+  using namespace std;
+#else
+# include <fstream.h>
+#endif
+
+#include <string>
 
 extern char *tzname[2];
 extern int   errno;
