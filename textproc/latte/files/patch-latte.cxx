--- latte.cxx.orig	Thu Oct  7 06:11:01 1999
+++ latte.cxx	Fri Mar 19 01:17:52 2004
@@ -19,6 +19,8 @@
 #include <latte-log.h>
 #include <restorer.h>
 
+using namespace std;
+
 void
 latte_init(bool path)
 {
