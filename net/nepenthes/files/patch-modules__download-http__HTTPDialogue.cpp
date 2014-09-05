--- modules/download-http/HTTPDialogue.cpp.orig
+++ modules/download-http/HTTPDialogue.cpp
@@ -27,6 +27,10 @@
 
  /* $Id: HTTPDialogue.cpp 836 2007-02-06 15:16:50Z common $ */
 
+#include <cstdio>
+#include <cstdlib>
+#include <cstring>
+
 #include "HTTPDialogue.hpp"
 
 
