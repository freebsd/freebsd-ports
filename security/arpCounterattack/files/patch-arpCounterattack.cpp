--- arpCounterattack.cpp.orig	2019-03-13 08:10:31 UTC
+++ arpCounterattack.cpp
@@ -25,13 +25,15 @@
 #include <fstream>
 #include <iostream>
 #include <queue>
-#include <tr1/unordered_map>
+#include <unordered_map>
 #include <vector>
 
 #ifdef __FreeBSD__
   #include <sys/ioctl.h>
 #endif
 
+#include <sys/types.h>
+#include <net/bpf.h>
 #include <errno.h>
 #include <pcap.h>
 #include <signal.h>
@@ -47,7 +48,6 @@
 #include "string.hpp"
 
 using namespace std;
-using namespace tr1;
 
 const string programName = "ARP Counterattack 1.2.0";
 string pidFileName = "/var/run/arpCounterattack.pid";
