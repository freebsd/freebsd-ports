--- tmpstore.cpp.orig	2013-10-06 17:14:20.000000000 +0400
+++ tmpstore.cpp	2013-10-06 17:15:03.000000000 +0400
@@ -12,6 +12,8 @@
  * Author: John Whitney <jjw@deltup.org>
  */
 
+#include <stdlib.h>
+#include <unistd.h>
 #include <signal.h>
 #include <string>
 #include <vector>
