
$FreeBSD$

--- CH2L.cpp.orig	Sun Nov 11 21:03:19 2001
+++ CH2L.cpp	Fri Feb 21 03:08:09 2003
@@ -18,6 +18,9 @@
  * Boston, MA 02111-1307, USA.
  *
  */
+
+using namespace std;
+
 #include "CH2L.h"
 #include "util.h"
 #include "safe_ostrstream.h"
@@ -28,7 +31,6 @@
 #include <assert.h>
 #include <fstream>
 
-using namespace std;
 using namespace Magick;
 
 #define ATTRIBUTENESTLIMIT	1000
@@ -2086,7 +2088,7 @@
 }
 
 
-void CH2L::_implied_font_end(const string &tagdelimiter="",int iterations=1)
+void CH2L::_implied_font_end(const string &tagdelimiter,int iterations)
 {
 	dump_text();
 	int cnt = 0;
@@ -2225,7 +2227,7 @@
 }
 
 ////////////////////////
-void CH2L::_implied_a_end(const string &tagdelimiter="",int iterations=1)
+void CH2L::_implied_a_end(const string &tagdelimiter,int iterations)
 {
 	dump_text();
 
@@ -3594,7 +3596,7 @@
 }
 
 
-void CH2L::_implied_div_end(const string &tagdelimiter="",int iterations=1) 
+void CH2L::_implied_div_end(const string &tagdelimiter,int iterations) 
 { 
 	bool did_something = false;
 	bool alignment_changed = false;
