--- classes/include/Signal.hh.orig	Fri Jun 15 18:25:43 2007
+++ classes/include/Signal.hh	Fri Jun 15 18:29:48 2007
@@ -47,6 +47,7 @@
 #include <signal.h>
 }
 
+using namespace std;
 typedef struct sigaction sigactStruct;
 
 //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
