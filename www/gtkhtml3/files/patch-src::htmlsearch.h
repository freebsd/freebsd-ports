
$FreeBSD$

--- src/htmlsearch.h	2002/03/25 14:12:56	1.1
+++ src/htmlsearch.h	2002/03/25 14:13:16
@@ -24,7 +24,7 @@
 #define _HTML_SEARCH_H_
 
 #include <sys/types.h>
-#include <regex.h>
+#include <gnuregex.h>
 #include "htmltypes.h"
 
 struct _HTMLSearch {
