--- latte-html.cxx.orig	Fri Oct 22 13:02:02 1999
+++ latte-html.cxx	Fri Mar 19 01:17:52 2004
@@ -22,6 +22,8 @@
 #include <cstdlib>
 #include <ctime>
 
+using namespace std;
+
 static bool in_pre = 0;
 static bool in_html = 0;
 
