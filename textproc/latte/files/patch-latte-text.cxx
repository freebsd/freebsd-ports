--- latte-text.cxx.orig	Sat Oct 16 16:37:18 1999
+++ latte-text.cxx	Fri Mar 19 01:17:52 2004
@@ -22,6 +22,8 @@
 #include <unistd.h>
 #include <ctime>
 
+using namespace std;
+
 static bool in_pre = 0;
 static unsigned int left_margin = 0;
 
