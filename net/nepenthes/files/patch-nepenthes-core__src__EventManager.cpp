--- nepenthes-core/src/EventManager.cpp.orig
+++ nepenthes-core/src/EventManager.cpp
@@ -27,6 +27,8 @@
 
 /* $Id: EventManager.cpp 1410 2007-10-12 13:07:23Z common $ */
 
+#include <cstdlib>
+
 #include "EventManager.hpp"
 #include "EventHandler.hpp"
 #include "Nepenthes.hpp"
