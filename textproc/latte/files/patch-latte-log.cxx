--- latte-log.cxx.orig	Tue Nov 10 06:19:23 1998
+++ latte-log.cxx	Fri Mar 19 01:17:52 2004
@@ -17,6 +17,8 @@
 
 #include <latte-log.h>
 
+using namespace std;
+
 ostream &
 actual_latte_log()
 {
