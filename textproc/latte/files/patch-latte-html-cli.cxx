--- latte-html-cli.cxx.orig	Thu Oct 21 03:05:04 1999
+++ latte-html-cli.cxx	Fri Mar 19 01:17:52 2004
@@ -22,6 +22,8 @@
 #include <cstring>
 #include <unistd.h>
 
+using namespace std;
+
 static void
 report_backtrace(const Latte_Error &err)
 {
