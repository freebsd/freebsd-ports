--- src/includes/MultiLineSubString.h.orig	2013-11-03 22:06:31.000000000 +0100
+++ src/includes/MultiLineSubString.h	2013-11-03 22:06:50.000000000 +0100
@@ -31,6 +31,7 @@
 #ifndef _MultiLineSubString_h
 #define _MultiLineSubString_h
 
+#include <limits.h>
 #include "AbstractMultiLineString.h"
 
 class MultiLineSubString : public AbstractMultiLineString
