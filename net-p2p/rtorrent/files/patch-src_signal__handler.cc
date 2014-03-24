--- src/signal_handler.cc.orig	2012-03-29 15:06:11.000000000 +0200
+++ src/signal_handler.cc	2014-02-02 22:46:43.000000000 +0100
@@ -38,6 +38,7 @@
 
 #include <signal.h>
 #include <stdexcept>
+#include <string>
 #include "rak/error_number.h"
 #include "signal_handler.h"
 
