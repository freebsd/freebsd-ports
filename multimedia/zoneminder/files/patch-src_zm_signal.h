--- src/zm_signal.h.orig	2009-03-20 15:07:00.000000000 +0300
+++ src/zm_signal.h	2011-04-08 17:48:07.396806893 +0400
@@ -20,8 +20,12 @@
 #ifndef ZM_SIGNAL_H
 #define ZM_SIGNAL_H
 
-#include <signal.h>
+
+#ifndef ZM_NO_CRASHTRACE
 #include <execinfo.h>
+#endif
+
+#include <signal.h>
 
 #include "zm.h"
 
