
$FreeBSD$

--- h2l.l.orig	Wed Oct 10 14:24:26 2001
+++ h2l.l	Fri Feb 21 03:10:30 2003
@@ -1,8 +1,10 @@
 %{
+using namespace std;
+
 #include "CLexData.h"
 #define YYSTYPE	CLexDataPtr
 
-#include "h2l.tab.cpp.h"
+#include "h2l.tab.hpp"
 #include "CH2L.h"
 #include "util.h"
 #include <assert.h>
