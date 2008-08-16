--- myregex.cc	2004-05-29 16:00:06.000000000 -0700
+++ myregex.cc	2008-03-02 23:03:02.000000000 -0800
@@ -21,6 +21,7 @@
 #endif
 #include <stdlib.h>
 #include "myregex.h"
+#include <string.h>
 
 
 static string regex_match_word_beginning_safe_str;
