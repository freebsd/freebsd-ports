--- ./apps/artstos/artstos.cc.orig	Mon Oct  2 13:05:13 2000
+++ ./apps/artstos/artstos.cc	Wed Sep 25 16:38:09 2002
@@ -52,14 +52,19 @@
 #include <errno.h>
 }
 
-#include <fstream.h>
-#include <string>
-
 #include "ArtsTosTable.hh"
 #include "ArtsIfIndexSelectionSet.hh"
 #include "ArtsTimeIntervalSelectionSet.hh"
 #include "ArtsPackageVersion.hh"
 
+#ifdef HAVE_FSTREAM
+# include <fstream>
+# include <iterator>
+  using namespace std;
+#else
+# include <fstream.h>
+#endif
+
 #ifndef NDEBUG
   #include "ArtsDebug.hh"
 #endif
@@ -108,7 +113,7 @@
     }
   }
 
-  if (hostAttribute) {
+  if (hostAttribute != arts.Attributes().end()) {
     inAddr.s_addr = hostAttribute->Host();
     cout << "router:  " << inet_ntoa(inAddr) << endl;
   }
@@ -126,7 +131,7 @@
   }
   cout << endl;
   
-  if (periodAttribute) {
+  if (periodAttribute != arts.Attributes().end() ) {
     periodTimes[0] = periodAttribute->Period()[0];
     periodTimes[1] = periodAttribute->Period()[1];
     localTm = localtime(&(periodTimes[0]));
