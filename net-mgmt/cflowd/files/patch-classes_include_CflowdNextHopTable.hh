--- classes/include/CflowdNextHopTable.hh.orig	Fri Jun 15 16:54:56 2007
+++ classes/include/CflowdNextHopTable.hh	Fri Jun 15 16:58:39 2007
@@ -52,6 +52,7 @@
 }
 
 #include <map>
+using namespace std;
 
 #include "ArtsPrimitive.hh"
 #include "CflowdNextHopTableTrafficCounter.hh"
