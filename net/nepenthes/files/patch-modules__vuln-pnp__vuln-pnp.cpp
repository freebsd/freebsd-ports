--- modules/vuln-pnp/vuln-pnp.cpp.orig
+++ modules/vuln-pnp/vuln-pnp.cpp
@@ -27,7 +27,8 @@
 
  /* $Id: vuln-pnp.cpp 550 2006-05-04 10:25:35Z common $ */
 
-#include <ctype.h>
+#include <cctype>
+#include <cstdlib>
 
 #include "vuln-pnp.hpp"
 #include "PNPDialogue.hpp"
