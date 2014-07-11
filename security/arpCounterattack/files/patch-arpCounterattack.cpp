--- arpCounterattack.cpp.orig	2010-11-04 01:26:49.000000000 +0000
+++ arpCounterattack.cpp
@@ -25,7 +25,7 @@
 #include <fstream>
 #include <iostream>
 #include <queue>
-#include <tr1/unordered_map>
+#include <unordered_map>
 #include <vector>
 
 #ifdef __FreeBSD__
@@ -47,7 +47,6 @@
 #include "string.hpp"
 
 using namespace std;
-using namespace tr1;
 
 const string programName = "ARP Counterattack 1.2.0";
 string pidFileName = "/var/run/arpCounterattack.pid";
