--- nepenthes-core/include/EventHandler.hpp.orig
+++ nepenthes-core/include/EventHandler.hpp
@@ -44,6 +44,8 @@
 #ifdef WIN32
 #include <time.h>
 #include <sys/timeb.h>
+#else
+#include <ctime>
 #endif
 
 //#include "Event.hpp"
