--- anteater/postfixfilter.cpp.orig	Fri Oct 24 00:11:11 2003
+++ anteater/postfixfilter.cpp	Sat Oct 25 03:00:35 2003
@@ -11,6 +11,7 @@
 #include "plugin.h"
 #include <ctime>
 #include <list>
+#include <algorithm>
 
 postfixFilter::postfixFilter() :
 		strPrefix( "postfix" ),
