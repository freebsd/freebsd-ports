--- modules/shellcode-signatures/sch_engine_unicode.cpp.orig
+++ modules/shellcode-signatures/sch_engine_unicode.cpp
@@ -27,6 +27,7 @@
 
 /* $Id: sch_engine_unicode.cpp 443 2006-03-27 19:55:16Z common $ */
 
+#include <cstring>
 #include <stdint.h>
 
 #include "sch_engine_unicode.hpp"
