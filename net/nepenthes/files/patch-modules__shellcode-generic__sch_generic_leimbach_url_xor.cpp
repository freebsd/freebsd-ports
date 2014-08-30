--- modules/shellcode-generic/sch_generic_leimbach_url_xor.cpp.orig
+++ modules/shellcode-generic/sch_generic_leimbach_url_xor.cpp
@@ -27,6 +27,8 @@
 
  /* $Id: sch_generic_leimbach_url_xor.cpp 836 2007-02-06 15:16:50Z common $ */
 
+#include <cstring>
+
 #include "sch_generic_xor.hpp"
 #include "sch_generic_leimbach_url_xor.hpp"
 
