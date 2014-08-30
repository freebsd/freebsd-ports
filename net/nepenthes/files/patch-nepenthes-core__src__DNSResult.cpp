--- nepenthes-core/src/DNSResult.cpp.orig
+++ nepenthes-core/src/DNSResult.cpp
@@ -27,6 +27,7 @@
 
 /* $Id: DNSResult.cpp 836 2007-02-06 15:16:50Z common $ */
 
+#include <cstring>
 #include "DNSResult.hpp"
 #include "Nepenthes.hpp"
 #include "LogManager.hpp"
