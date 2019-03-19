--- src/main.cpp.orig	2011-09-23 20:09:12 UTC
+++ src/main.cpp
@@ -24,6 +24,7 @@
 
 #include <ctime>
 #include <cstdlib>
+#include <unistd.h>
 
 /** This function runs the Frobby console interface. the ::main
     function calls this function after having set up DEBUG-specific
