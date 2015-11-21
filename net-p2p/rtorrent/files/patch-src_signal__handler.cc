--- src/signal_handler.cc.orig	2014-05-14 14:30:51 UTC
+++ src/signal_handler.cc
@@ -38,6 +38,7 @@
 
 #include <signal.h>
 #include <stdexcept>
+#include <string>
 #include "rak/error_number.h"
 #include "signal_handler.h"
 
