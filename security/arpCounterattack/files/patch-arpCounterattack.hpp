--- arpCounterattack.hpp.orig	2010-11-04 01:26:14.000000000 +0000
+++ arpCounterattack.hpp
@@ -24,7 +24,7 @@
 
 #include <string>
 #include <vector>
-#include <tr1/unordered_map>
+#include <unordered_map>
 
 #include <sys/socket.h>
 #include <sys/time.h>
@@ -55,7 +55,7 @@ struct Interface {
   std::string replyName;
   pcap_t *replyDescriptor;
   ModeType mode;
-  std::tr1::unordered_map <uint32_t, std::string> pairs;
+  std::unordered_map <uint32_t, std::string> pairs;
 };
 
 struct ARPCorrection {
