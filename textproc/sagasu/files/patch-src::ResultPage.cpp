--- src/ResultPage.cpp.orig	Thu Oct  9 23:20:10 2003
+++ src/ResultPage.cpp	Thu Oct  9 23:21:01 2003
@@ -22,6 +22,7 @@
 
 #include "ResultPage.h"
 
+#include <assert.h>
 #include <libintl.h>
 #define _(String) gettext (String)
 #define gettext_noop(String) String
