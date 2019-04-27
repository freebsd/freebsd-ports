--- CH2L.cpp.orig	2001-11-11 20:03:19 UTC
+++ CH2L.cpp
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
@@ -27,8 +30,9 @@
 #include <stdlib.h>
 #include <assert.h>
 #include <fstream>
+#include <cstring>
+#include <strings.h>
 
-using namespace std;
 using namespace Magick;
 
 #define ATTRIBUTENESTLIMIT	1000
@@ -2086,7 +2090,7 @@ void CH2L::make_font_start()
 }
 
 
-void CH2L::_implied_font_end(const string &tagdelimiter="",int iterations=1)
+void CH2L::_implied_font_end(const string &tagdelimiter,int iterations)
 {
 	dump_text();
 	int cnt = 0;
@@ -2225,7 +2229,7 @@ void CH2L::end_sup()
 }
 
 ////////////////////////
-void CH2L::_implied_a_end(const string &tagdelimiter="",int iterations=1)
+void CH2L::_implied_a_end(const string &tagdelimiter,int iterations)
 {
 	dump_text();
 
@@ -3594,7 +3598,7 @@ void CH2L::_idle_tag_end(const string &htmltag)
 }
 
 
-void CH2L::_implied_div_end(const string &tagdelimiter="",int iterations=1) 
+void CH2L::_implied_div_end(const string &tagdelimiter,int iterations) 
 { 
 	bool did_something = false;
 	bool alignment_changed = false;
@@ -3945,7 +3949,7 @@ bool CH2L::openTableDimensionsFile()
 
 		mTableDimensionsFileName = tsp;
 		mTableDimensionsFile.open(tsp.c_str());
-		return mTableDimensionsFile;
+		return true;
 		}
 	else 
 		{
