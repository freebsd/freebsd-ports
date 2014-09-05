--- modules/shellcode-generic/sch_generic_unicode.cpp.orig
+++ modules/shellcode-generic/sch_generic_unicode.cpp
@@ -28,6 +28,9 @@
 /* $Id: sch_generic_unicode.cpp 2245 2006-01-06 16:46:44Z common $ */
 
 
+#include <cstdlib>
+#include <cstring>
+
 #include "sch_generic_unicode.hpp"
 #include "LogManager.hpp"
 #include "Message.hpp"
