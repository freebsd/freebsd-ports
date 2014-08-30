--- modules/shellcode-generic/sch_generic_linkxor.cpp.orig
+++ modules/shellcode-generic/sch_generic_linkxor.cpp
@@ -27,6 +27,7 @@
 
 /* $Id: sch_generic_linkxor.cpp 2215 2005-12-23 16:54:36Z common $ */ 
 
+#include <cstring>
 #include "sch_generic_linkxor.hpp"
 #include "Nepenthes.hpp"
 #include "Message.hpp"
