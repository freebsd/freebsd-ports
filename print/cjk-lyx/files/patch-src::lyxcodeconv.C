--- src/lyxcodeconv.C.orig	Thu Jul 11 19:55:02 2002
+++ src/lyxcodeconv.C	Thu Jul 11 19:55:36 2002
@@ -11,6 +11,10 @@
 #include "LString.h"
 #include "lyxcodeconv.h"
 
+#include <iostream>
+
+using namespace std;
+
 LyXCodeConv codeconverter;     //global
 
 size_t LyXCodeConv::lyxmbstowcs(wchar_t *wcs, const char *cs, size_t n)
