--- ./apps/artsnexthops/artsnexthops.cc.orig	Mon Oct  2 13:05:12 2000
+++ ./apps/artsnexthops/artsnexthops.cc	Wed Sep 25 16:38:09 2002
@@ -51,14 +51,21 @@
 #include <errno.h>
 }
 
-#include <fstream.h>
-#include <string>
-
 #include "ArtsNextHopTable.hh"
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
+#include <string>
+
 #ifndef NDEBUG
   #include "ArtsDebug.hh"
 #endif
@@ -116,7 +123,7 @@
     }
   }
   
-  if (hostAttribute) {
+  if (hostAttribute != arts.Attributes().end()) {
     inAddr.s_addr = hostAttribute->Host();
     cout << "router:  " << inet_ntoa(inAddr) << endl;
   }
@@ -135,7 +142,7 @@
   cout << endl;
   
   periodAttribute = arts.FindPeriodAttribute();
-  if (periodAttribute) {
+  if (periodAttribute != arts.Attributes().end() ) {
     periodTimes[0] = periodAttribute->Period()[0];
     periodTimes[1] = periodAttribute->Period()[1];
     localTm = localtime(&(periodTimes[0]));
