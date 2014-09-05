--- modules/shellcode-generic/sch_generic_konstanz_xor.cpp.orig
+++ modules/shellcode-generic/sch_generic_konstanz_xor.cpp
@@ -27,6 +27,7 @@
 
 /* $Id: sch_generic_konstanz_xor.cpp 2215 2005-12-23 16:54:36Z common $ */ 
 
+#include <cstring>
 #include "sch_generic_konstanz_xor.hpp"
 #include "Nepenthes.hpp"
 #include "Message.hpp"
