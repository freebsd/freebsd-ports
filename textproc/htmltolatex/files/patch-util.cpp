--- util.cpp.orig	2001-10-10 12:24:27 UTC
+++ util.cpp
@@ -18,9 +18,13 @@
  * Boston, MA 02111-1307, USA.
  *
  */
+
+using namespace std;
+
 #include "util.h"
 #include <map>
 #include <ctype.h>
+#include <cstring>
 #include <sys/param.h>
 #include <stdio.h>
 #include <unistd.h>
@@ -35,7 +39,6 @@ extern "C"{
 #include "fetch.h"
 }
 #endif
-using namespace std;
 
 static map<string,int> gsSpecialTable;
 
