--- modules/vuln-msmq/vuln-msmq.cpp.orig
+++ modules/vuln-msmq/vuln-msmq.cpp
@@ -27,7 +27,8 @@
 
  /* $Id: vuln-msmq.cpp 550 2006-05-04 10:25:35Z common $ */
 
-#include <ctype.h>
+#include <cctype>
+#include <cstdlib>
 
 #include "vuln-msmq.hpp"
 #include "MSMQDialogue.hpp"
