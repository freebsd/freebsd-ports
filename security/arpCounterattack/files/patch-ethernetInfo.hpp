--- ethernetInfo.hpp.orig	2010-10-11 21:46:00.000000000 +0000
+++ ethernetInfo.hpp
@@ -27,7 +27,7 @@
 
 #include <fstream>
 #include <string>
-#include <tr1/unordered_map>
+#include <unordered_map>
 
 #include <arpa/inet.h>
 
@@ -46,8 +46,8 @@ class EthernetInfo {
     const std::string &find(const std::string oui);
     const std::string &find(const char *oui);
   private:
-    std::tr1::unordered_map <std::string, std::string> ouiMap;
-    std::tr1::unordered_map <std::string, std::string>::const_iterator ouiItr;
+    std::unordered_map <std::string, std::string> ouiMap;
+    std::unordered_map <std::string, std::string>::const_iterator ouiItr;
     std::string _oui;
     std::string empty;
     std::string multicast;
