--- sim/api/fetch.cpp.orig	Fri Oct 15 01:17:45 2004
+++ sim/api/fetch.cpp	Fri Oct 15 01:21:31 2004
@@ -24,6 +24,8 @@
 #include <qthread.h>
 #include <qtimer.h>
 
+#include <time.h>
+
 typedef map<my_string, string> HEADERS_MAP;
 
 class FetchThread;
